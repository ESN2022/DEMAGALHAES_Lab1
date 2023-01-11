# DEMAGALHAES_Lab1

# Hardware Description
## Architecture
On souhaite implémenter un chenillard ou "led chaser" sur notre DE10-Lite, pour se faire on commence tout d'abord par décrire l'architecture de notre système.
Il sera composé des éléments suivants : 
* Nios 2
* RAM
* CLK
* LEDs
* Boutons
* Interrupteurs
* JTAG

Les élements seront connectés les uns aux autres à travers le bus Avalon et décriront l'architecture suivante :
![archESN11_Lab1](https://user-images.githubusercontent.com/77203492/211789225-1ee13f03-ab92-4d16-b33a-704f05b94f45.png)

## Platform Designer
Réalisons maintenant cette architecture sur **Platform Designer** :
![image](https://user-images.githubusercontent.com/77203492/211787624-8a138f02-0409-4d70-b56d-855e1f2428e8.png)
On peut voir les différentes connections entre les élements de notre architecture, à noter les connections importantes :
* les broches **irq** des *switchs*,*buttons* et *jtag* sont reliées à la broche **irq** du NIOS, pour activer les interruptions.
* On peut noter également les broches **s1** des *switchs*,*buttons* et *leds* qui sont reliées à la broche **data_master** du NIOS (canal de donnée).
* Dans la configuration des boutons et des switchs, on peut définir comment les interruptions seront détectées, notamment sur les fronts montant/descendant.
Dès que l'architecture du système est bien configurer, on peut assigner les addresses et génerer le HDL de notre système.

## Top Level design
Passons désormais à la description du design VHDL :
Sur l'image ci-dessous vous pouvez constater le fichier VHDL qui décrit les entrées sorties du système et le mapping sur le descriptif réalisé sur plateform designer.
![image](https://user-images.githubusercontent.com/77203492/211788882-e9fb8c02-f705-4f8d-902c-ebbc174964a9.png)

## Pin Assignement
Sur les 2 images qui suivent vous retrouverez, l'association entre les entrées sorties et les pin physique du FPGA.
On peut voir les différentes spécifications associées à chaque pin, le niveau de tension etc..

![image](https://user-images.githubusercontent.com/77203492/211789038-0e8fe222-ab16-44d8-8a10-a56bc091b9f2.png)
![image](https://user-images.githubusercontent.com/77203492/211788984-3e8c7cf4-0290-4472-b32b-f233fd7b02e2.png)

# Software Description
Dans cette partie je vais m'attarder sur la description du fonctionnement de chacun des programmes :
## Chenillard Simple
Le chenillard simple comme son nom l'indique, allume automatiquement les LEDs de la façon souhaitée sans pouvoir modifier la vitesse ou arrêter le chenillard.
On utilise la fonction **IOWR_ALTERA_AVALON_PIO_DATA(PIO_BASE,DATA)** Pour allumer les LEDs une à une dans une boucle for.

## Chenillard Bouton (Polling)
Le chenillard bouton fonctionne selon le principe du polling c'est a dire qu'on va venir interroger continuellement le périphérique pour savoir si le bouton à été pressé où non, c'est sans doute la façon la moins optimiser puisqu'on vient surchargé le processeur pour rien d'où l'intérêt d'utiliser des interruptions qui vont permettre de déclencher le chenillard seulement lorsque le bouton est pressé.
Pour mettre en place ce chenillard il suffit simplement d'utiliser la fonction suivante, **IORD_ALTERA_AVALON_PIO_DATA(BUTTONS_BASE)** qui permet de lire la valeur du bouton, ensuite selon cette valeur on démarre le chenillard.

## Chenillard Final (Interruptions)
Le chenillard final, pour commencer, j'ai d'abord défini une routine d'interruption pour le bouton, pour être sûr de comprendre le principe et de démarrer le chenillard avec. 
La fonction **static void handle_button_interrupts(void* context, alt_u32 id)** permet de définir l'interruption du bouton.
Et la fonction **static void init_button_pio()** permet d'initialiser le bouton avec son interruption, il est important qu'elles soient définis en static pour que le compilateur ne les optimises pas.


Ceci réalisé j'ai d'abord commencer par implémenter les switchs par la méthode du Polling comme vu précédemment, pour définir la vitesse du chenillard.
Pour se faire j'ai utilisé la même fonction que pour le chenillard bouton, pour lire la valeur des switchs.
_N.B._ **Le Switch[9] sert de Switch reset, il reset le programme à l'état bas.**

J'ai donc lors de la lecture des switchs prendre en compte ce Switch [9], dans le programme de la vitesse.
Je réalise un Switch case sur la valeur des switchs en partant de 0x200 (0b10 0000 0000).
Pour les vitesses ont peut régler 5 niveaux de vitesses à l'aide des switchs 1 à 5, pour qu'une vitesse soit prise en compte il faut 1 seul Switch à l'état haut à la fois.

Ensuite j'ai ajouté un flag stop pour permettre avec l'appui sur le bouton pour démarré le chenillard et par un appui à nouveau pour éteindre le chenillard.
Sans doute que le programme n'est pas le plus optimisé surtout au niveau de la lecture des switchs et du calcul de la vitesse mais celà est suffisant pour comprendre le fonctionnement des interruptions.

# Resultat
Voici une courte vidéo démontrant le principe de fonctionnement :

# Conclusion 
Dans ce TP, j'ai bien compris le principe et l'intérêt d'utiliser les interruptions, ainsi que l'approche particulière que demandent les FPGA, en définissant d'abord l'architecture **Hardware** puis la partie **Software** et enfin l'aspect **Compilation** sur le shell de nios.
