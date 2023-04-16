int incomingByte ;      
char myStr[1000];
char value;
int i = 0;
char time;
int lastMessageIndex = 0;
String Message = "";
int idx0,idx1,idx2,idx3;
String distAv,distAr,distG,distD;
String keyWords[] = {"  distAv =","   distAr =","   distG =","   distD ="};
void setup() {
 Serial.begin(9600);
}

void loop() {
   // check if data is available
  while (Serial.available() > 0) {
      incomingByte = Serial.read();
      myStr[i]=(char)incomingByte;
      //Serial.print(myStr[i]);
      i = i+1;
      if(incomingByte == 13){
        Message = "";
        for (int k = lastMessageIndex; k <=i; k++)
          { 
            Message = Message+myStr[k];
          }
        //Serial.println("le message reçu est : "+Message);
        lastMessageIndex = i;
        idx0=Message.indexOf(keyWords[0]);
        if(idx0>=0){
          idx1=Message.indexOf(keyWords[1]);
          if(idx1>=0){
            idx2=Message.indexOf(keyWords[2]);
            if(idx2>=0){
              idx3=Message.indexOf(keyWords[3]);
              if(idx3>=0){
                    distAv = Message.substring(idx0+keyWords[0].length(),idx1);
                    distAr = Message.substring(idx1+keyWords[1].length(),idx2);
                    distG = Message.substring(idx2+keyWords[2].length(),idx3);
                    distD = Message.substring(idx3+keyWords[3].length());
                    //Serial.println("trouvé : "+(String)distAv+"  "+ (String)distAr+ "  "+(String)distG+"  "+(String)distD+"   ");
                    
                }
              }
            }
          }
      }
  }
}
