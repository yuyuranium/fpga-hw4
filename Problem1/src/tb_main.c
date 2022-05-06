#include <stdio.h>
#include "xil_printf.h"
#include "xil_io.h"
#include "xparameters.h"

int main(){
	u32 a, b, c, d, a_read, b_read, c_read, d_read;

	a = 0xffffffff;
	b = 0x11111111;
	c = 0x22222222;
	d = 0x33333333;

	printf("\r\nHW4 Program Start.\r\n");
	
	
	/*
	 *
	 * Read initial data test
	 *
	 */
	
	//Read Data from BRAM
	a_read = Xil_In32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 0);
	b_read = Xil_In32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 4);
	c_read = Xil_In32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 28);
	d_read = Xil_In32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 64;
	
	printf("Offset = 0, Data = %x\r\n", a_read);
	printf("Offset = 4, Data = %x\r\n", b_read);
	printf("Offset = 28, Data = %x\r\n", c_read);
	printf("Offset = 64, Data = %x\r\n", d_read);
	
	/*
	 *
	 * Write data test
	 *
	 */

	//Write Data in BRAM
	Xil_Out32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 0, a);
	Xil_Out32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 4, b);
	Xil_Out32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 8, c);
	Xil_Out32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 12, d);

	//Read Data from BRAM
	a_read = Xil_In32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 0);
	b_read = Xil_In32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 4);
	c_read = Xil_In32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 8);
	d_read = Xil_In32(XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR + 12);

	printf("Offset = 0, Data = %x\r\n", a_read);
	printf("Offset = 4, Data = %x\r\n", b_read);
	printf("Offset = 8, Data = %x\r\n", c_read);
	printf("Offset = 12, Data = %x\r\n", d_read);

}
