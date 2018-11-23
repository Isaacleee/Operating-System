#include <stdio.h>

int readcount, writecount;
semaphore x=1, y=1, z=1, wsem=1,rsem=1;

void reader(){
  semWait(z);
    semWait(rsem);
      semWait(x);
        readcount++;
        if(readcount ==1)
          semWait(wsem);
      semSignal(x);
    semSignal(rsem);
  semSignal(z);
  READUNIT();
  semWait(x);
        readcount--;
        if(readcount ==0)
        semSignal(wsem);
  semSignal(x);
}
void writer(){
  while(true){
    semWait(y);
      Writecount++;
      if(writecount ==1)
        semWait(rsem);
    semSignal(y);
    semWait(wsem);
    WRITEUNIT();
    semSignal(swem);
    semWsait(y);
      writecount--;
      if(sritecount==0)
        semSignal(rsem);
    semSignal(y);
  }
}
void main(){
  readcount = writecount =0;
  parbegin(reader,writer);
}
