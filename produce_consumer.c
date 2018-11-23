semaphore n=0;
sempahore s=1;
void producer(){
  while(true){
    produce();
    semWait(s);
    append();
    semSignal(s);
    semSignal(n);
  }
}
void consumer(){
  while(true){
    semWait(n);
    semWait(s);
    take();
    semSigmal(s);
    consume();
  }
}
