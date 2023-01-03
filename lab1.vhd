library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


entity lab1 is
	port(
		clk : in std_logic := '0';
		reset_n : in std_logic :='0');
end entity lab1;

architecture rit of lab1 is
	component lab1_sys is
		  port (
				clk_clk       : in std_logic := 'X'; -- clk
				reset_reset_n : in std_logic := 'X'  -- reset_n
		  );
	end component lab1_sys;

begin
	u0 : component lab1_sys
        port map (
            clk_clk       => clk,      --   clk.clk
            reset_reset_n => reset_n -- reset.reset_n
        );
end architecture;