module tb();
    reg clk;
    reg rst;
    //Inputs
    reg [9:0] ADDRA;
    reg [31:0] DINA;
    reg ENA;
    reg [3:0] WEA;
    reg [9:0] ADDRB;
    reg [31:0] DINB;
    reg ENB;
    reg [3:0] WEB;
    //outputs
    wire [31:0] DOA;
    wire [31:0] DOB;
    
    BRAM bram(
    /*PortA*/
    .addra(ADDRA),
    .clka(clk),
    .dina(DINA),
    .douta(DOA),
    .ena(ENA),
    .rsta(rst),
    .wea(WEA),
    /*PortB*/
    .addrb(ADDRB),
    .clkb(clk),
    .dinb(DINB),
    .doutb(DOB),
    .enb(ENB),
    .rstb(rst),
    .web(WEB)
    );
    
    initial begin
    //Initailize
    clk=1'b0; rst=1'b1; ENA=1'b0; ENB=1'b0; WEA=4'b0000; WEB=4'b0000;
    ADDRA=10'd0; ADDRB=10'd0; DINA=32'd0; DINB=32'd0;
    #10
    rst = 1'b0;
    #10
    
    //Test READ 
    rst = 1'b1;
    ENA=1'b1; ENB=1'b1;
    
    ADDRA=10'd0; ADDRB=10'd4;
    #100
    ADDRA=10'd28; ADDRB=10'd64;
    #100
    
    //Test Wirte
    WEA=4'b1111; WEB=4'b1111;
    ADDRA=10'd0; ADDRB=10'd4;
    DINA=32'hffffffff; DINB=32'hffffffff;
    #100
    WEA=4'b0000; WEB=4'b0000;
    ADDRA=10'd0; ADDRB=10'd4;
    DINA=32'd0; DINB=32'd0;
    
    
    end
    
     always #5 clk = ~clk ;
     
endmodule

