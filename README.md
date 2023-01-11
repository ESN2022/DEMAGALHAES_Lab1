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
* les broches **irq** des *switchs*,*buttons* et *jtag* sont reliées à la broche **irq** du NIOS.
* On peut noter également les broches **s1** des *switchs*,*buttons* et *leds* qui sont reliées à la broche **data_master** du NIOS (canal de donnée)

Dès que l'architecture du système est bien configurer, on peut assigner les addresses et génerer le HDL.
## Top Level design
Passons désormais à la description du design VHDL :
![image](https://user-images.githubusercontent.com/77203492/211788882-e9fb8c02-f705-4f8d-902c-ebbc174964a9.png)

## Pin Assignement
![image](https://user-images.githubusercontent.com/77203492/211789038-0e8fe222-ab16-44d8-8a10-a56bc091b9f2.png)
![image](https://user-images.githubusercontent.com/77203492/211788984-3e8c7cf4-0290-4472-b32b-f233fd7b02e2.png)

# Software Description
## Chenillard Simple
## Chenillard Bouton (Polling)
## Chenillard Final (Interruptions)
# Resultat
