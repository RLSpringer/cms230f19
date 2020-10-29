#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//for data processing instruction
/*
  Isolate the 4 bit opcode
  Use opcode chart to determine which instruction
  Extract and decode Op1, Op2, and Destination
  Extract immediate bit.
  Decode Op2 based on either immediate or not interpretation
  Format assembly code string based on opcode and then the needed pieces of op1, op2, and dest. 
*/
void dataProcessing(uint i) {
  int Op1 = 0;
  int Op2 = 0;
  int immediate = 0;
  int destination = 0;
  int opCode = 0;
  int bit = i;

  opCode = bit >> 21;
  opCode &= 0x0000000f;
  Op1 = bit >> 16;
  Op1 &= 0x0000000f;
  Op2 = bit & 0x00000fff;
  destination = bit >> 12;
  destination &= 0x0000000f;
  immediate = bit >> 25;
  immediate &= 0x0000000f;

  if (opCode == 0x2) {
    if (immediate == 0x1) {
      printf("sub r%d, r%d, #%d\n", destination, Op1, Op2);
    } else {
      printf("sub r%d, r%d, r%d\n", destination, Op1, Op2);
    }
  } else if (opCode == 0x4) {
    if (immediate == 0x1) {
      printf("add r%d, r%d, #%d\n", destination, Op1, Op2);
    } else {
      printf("add r%d, r%d, r%d\n", destination, Op1, Op2);
    }
  } else if (opCode == 0xd) {
    if (immediate == 0x1) {
      printf("mov r%d, #%d\n", destination, Op2);
    } else {
      printf("mov r%d, r%d\n", destination, Op2);
    }
  } else if (opCode == 0xa) {
    if (immediate == 0x1) {
      printf("cmp r%d, #%d\n", Op1, Op2);
    } else {
      printf("cmp r%d, r%d\n", Op1, Op2);
    }
  }


}

//for loads and stores
/*
  Extract immediate bit - remember this is backwards!
  Extract Store bit: 0 for stores, 1 for loads
  Extract next 4 bits: base register
  Extract next 4 bits: destination register
  Last 12 are offset (to base reg) or reg
*/
void loadStore(uint i){
  int bit = i;
  int immediate = 0;
  int store = 0;
  int base = 0;
  int destination = 0;
  int offset = 0;

  immediate = bit >> 25;
  immediate &= 0x0000000f;
  store = bit >> 20;
  store &= 0x00000001;
  base = bit >> 16;
  base &= 0x0000000f;
  destination = bit >> 12;
  destination &= 0x0000000f;
  offset = bit & 0x00000fff;

  if (store == 0x1) {
    if (immediate == 0x1 || offset == 0x0) {
      printf("ldr r%d, [r%d]\n", destination, base);
    } else {
      printf("ldr r%d, [r%d, #%d]\n", destination, base, offset);
    }
  } else {
    if (immediate == 0x1 || offset == 0x0) {
      printf("str r%d, [r%d]\n", destination, base);
    } else {
      printf("str r%d, [r%d, #%d]\n", destination, base, offset);
    }    
  }


}

//for branching instruction:
/*
  Look at 4 condition bits
  Use these to determine which type of branching
  Use lower 24 bits to formulate target address 
*/
void branch(uint i) {
  int bit = i;
  bit = bit >> 28;
  bit &= 0x0000000f;
  int targetAddress = i << 7;
  targetAddress = targetAddress >> 7;


  switch (bit) {
    case 0x0:
      printf("beq <PC + 0x%x>\n", targetAddress);
      break;
    case 0x1:
      printf("bne <PC + 0x%x>\n", targetAddress);
      break;
    case 0xa:
      printf("bge <PC + 0x%x>\n", targetAddress);
      break;
    case 0xb:
      printf("blt <PC + 0x%x>\n", targetAddress);
      break;
    case 0xc:
      printf("bgt <PC + 0x%x>\n", targetAddress);
      break;
    case 0xd:
      printf("ble <PC + 0x%x>\n", targetAddress);
      break;
    case 0xe:
      printf("b <PC + 0x%x>\n", targetAddress);
  }


}

//determine category of instruction
void category(uint i) {
  int bit = i;
  int bit2 = i;
  int bit3 = i;
  bit = bit >> 25;
  bit &= 0x00000007;
  bit2 = bit2 >> 26;
  bit2 &= 0x00000003;
  bit3 = bit3 >> 26;
  bit3 &= 0x00000003;
  

  if (bit == 0x5) {
    branch(i);
  } else if (bit2 == 0x0) {
    dataProcessing(i);
  } else if (bit3 == 0x1) {
    loadStore(i);
  } else {
    printf("Undefined instruction");
  }
}

int main(int argc, char* argv[]) {
  
  char line[50];
  char data[9];
  char *ptr;
  uint instruction = 0;

  //check number of command line arguments
  if (argc != 2) {
    printf("Incorrect usage\n");
    printf("Correct usage: decode input_file.txt\n");
    return -1;
  }

  //try to open file from argument
  FILE* fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("File could not be opened.\n");
    return -1;
  }

  //read lines from file
  //if line isn't empty (only contains \n char)
  //extract hex value in line (remove comments)
  //and store it in a uint
  //pass instruction to category function
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (line[0] == '\n') {
      printf("\n");
    } else {
      for (int i = 0; i < 9; i++) {
        data[i] = line[i];
      }
      instruction = strtoul(data, &ptr, 16);
      category(instruction);
    }
  }

  // close the fp and exit
  fclose(fp);
  return EXIT_SUCCESS;
}