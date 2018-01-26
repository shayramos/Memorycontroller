module VGAController(Clock25, Reset, Data, read_en, Blank, Hsync, Vsync, R, G, B);

	input Clock25, Reset;
	input Ddata[23:0];
	output reg read_en;
	output reg[7:0] R, G, B;
	output wire Blank, Vsync, Hsync;
	
	
	VGASincController inst_1(.clock(Clock25), .reset(Reset), .blank(Blank), .hsync(Hsync), .vsync(Vsync), hcont, vcont);
	VGADataController inst_2(.clock(Clock25), .reset(Reset), .data(Data), hcont, vcont, .read_en(Vsync), .R(R), .G(G), .B(B));
endmodule
