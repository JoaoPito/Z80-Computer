int syncPin = 2;//Pino sincronização
int imgEnPin = 3;//Pino ativar imagem(Ativo HIGH)
int imgEnPinLO = 7;//Pino ativar imagem(Ativo LOW)

int CCRstPin = 4;//Pino Reset contador de colunas(Ativo LOW)
int RCRstPin = 5;//Pino Reset Contador de linhas(Ativo LOW)
int RCClkPin = 6;//Pino Clock Contador de linhas

int rowCounter = 0;//Contador de linhas
const int totalRows = 248;//Numero de linhas

void setup() {

  pinMode(syncPin,OUTPUT);
  pinMode(imgEnPin,OUTPUT);
  pinMode(imgEnPinLO,OUTPUT);
  
  pinMode(CCRstPin,OUTPUT);
  pinMode(RCRstPin,OUTPUT);
  pinMode(RCClkPin,OUTPUT);
  
  //Desativa os pinos
  digitalWrite(syncPin,LOW);
  digitalWrite(imgEnPin,LOW);
  digitalWrite(imgEnPinLO,HIGH);
  //Reseta os contadores
  digitalWrite(RCRstPin,LOW);//Contador de linhas
  digitalWrite(RCClkPin,LOW);
  digitalWrite(RCClkPin,HIGH);
  digitalWrite(RCClkPin,LOW);  
  digitalWrite(RCRstPin,HIGH);
  
  digitalWrite(CCRstPin,LOW);//Contador de colunas
  digitalWrite(CCRstPin,HIGH);
}

void loop() {
  if(rowCounter<=totalRows){
    // PINS: 76543210
    PORTD = B10110000;//HSYNC
    delayMicroseconds(4);
    
    PORTD = B10110100;//FRONT PORCH
    delayMicroseconds(8);
        
    PORTD = B00111100;//Ativa o video
    delayMicroseconds(49);
    
    PORTD = B10110100;//Desativa o video
    PORTD = B01110100;//Incrementa o contador de linhas e limpa o contador de colunas
    delayMicroseconds(1);
    PORTD = B10110100;
    rowCounter++;
    
  }else{
    Vsync();
    rowCounter = 0;
  }

}

void Vsync(){
  
  //PORTD = B10110100;//Desativa o video
  //delayMicroseconds(52);
    
  //POSITIVE PULSES
  //PULSE 1
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);  
  //PULSE 2
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  //PULSE 3
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  //PULSE 4
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  //PULSE 5
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  //PULSE 6
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  
  //NEGATIVE PULSES
  //PULSE 1
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(30);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(2);
  //PULSE 2
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(30);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(2);
  //PULSE 3
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(30);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(2);
  //PULSE 4
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(30);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(2);
  //PULSE 5
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(30);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(2);
  //PULSE 6
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(30);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(2);

  //POST POSITIVE PULSES
  //PULSE 1
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  //PULSE 2
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  //PULSE 3
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  //PULSE 4
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  //PULSE 5
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  //PULSE 6
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(2);
  PORTD = B10110100;//FRONT PORCH(Black Level)
  delayMicroseconds(30);
  
  PORTD = B10110000;//HSYNC(Sync Level)
  delayMicroseconds(4);
  
}

