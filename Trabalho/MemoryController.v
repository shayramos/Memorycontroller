module MemoryController(Blank, Hsync, Vsync, R, G, B, CoordX, CoordY, Clock50Mhz, Reset);

	output wire Blank, Hsync, Vsync;
	output [7:0] R, G, B;
	input Clock50Mhz, Reset;
	input[10:0] CoordX, CoordY;
	
VGAController inst_VGA(.Blank(Blank), 
							  .Hsync(Hsync), 
							  .Vsync(Vsync), 
							  .R(R), 
							  .G(G), 
							  .B(B), 
							  .Reset(Reset));

VerificaCoord(.coordX(CoordX), 
				  .coordY(CoordY));

endmodule
