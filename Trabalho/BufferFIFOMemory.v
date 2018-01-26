module BufferFIFOMemory(memclk, wrptr, rdptr, wren, rden,  wrdata, rddata);

	input memclk, wren, rden; 
	input [5:0]wrptr, rdptr;
	input [23:0]wrdata;
	output reg[23:0] rddata;
	
	reg [23:0]buffer[0:63]		//calcular a profunfidade depois

	always@(posedge memclk) begin
		if(wren) begin
			buffer[wrptr] <= wrdata;
		end
	end
	
	always@(posedge memclk) begin
		if(rden) begin
			rddata <= buffer[rdptr]; 
		end
	end
	
endmodule
