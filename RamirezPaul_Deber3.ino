/*
 * Deber #3
 * Autor: Ramirez Paul
 * Objetivo: Diseñar juego de preguntas por comunicacion serial
 * Fecha: 30/11/2020
 */
 //Pines para display
const int A=13;
const int B=12;
const int C=11;
const int D=10;
 //Preguntas
String p1="Los gatos tienen 4 patas?";
String p2="La Tierra es el 4to planeta del Sistema Solar?";
String p3="La capital de Australia es Sidney?";
String p4="El electron tiene carga positiva?";
String p5="La ballena es un mamifero?";
String p6="La capital del Ecuador es Quito?";
String p7="Ecuador es el pais mas grande del mundo?";
String p8="El rio Nilo es el mas largo del mundo?";
//Conteo Respuestas
int r1=0;
int r2=0;
int r3=0;
int r4=0;
int r5=0;
int r6=0;
int r7=0;
int r8=0;
//Puntaje Final
int puntaje=0;
//lectura de datos ingresados
String d1;
String d2;
String d3;
String d4;
String d5;
String d6;
String d7;
String d8;
int inicio=1;
int numero;
int i=0;


void setup() {
  //Pines display
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);

  //Comunicacion serial
  Serial.begin(9600);
  Serial.println("-----Juego de preguntas------");  
  Serial.println(" ");
  Serial.println("Banco de Preguntas:");
  Serial.println(p1);
  Serial.println(p2);
  Serial.println(p3);
  Serial.println(p4);
  Serial.println(p5);
  Serial.println(p6);
  Serial.println(p7);
  Serial.println(p8);
  Serial.println(" ");
  Serial.println("Responda 'si' o 'no' a cada pregunta");
  Serial.println(" ");
}

void loop() {
  delay(50);//tiempo de ejecucion de programa para variar la funcion random
  if(inicio==1){
    inicio=0;
    //ciclo for para impresion de solo 5 de las 8 preguntas
    for(i=0;i<5;i++){
      delay(350);//tiempo de ejecucion de programa para variar la funcion random
      randomSeed(millis());//semilla randomica que toma el tiempo de ejecucion variante para calcular los numeros aleatorios
      numero=random(0,8);//numeros random de 0 a 8
      //Pregunta numero 1
      if(numero==0){
        Serial.println(p1);
        delay(3000);//Tiempo qe tiene el usuario para responder (3s)
        if(Serial.available()>0){
          d1=Serial.readString();//lectura de la respuesta ingresada
          if(d1=="si"){//condicion para validar respuesta
            r1=1;//si la respuesta es correcta la calificacion es de un punto
            Serial.println(" Correcto");
          }else{
            Serial.println(" Incorrecto");
          }
        }
        Serial.println(" ");
      }
      //pregunta 2
      if(numero==1){
        Serial.println(p2);
        delay(3000);//Tiempo qe tiene el usuario para responder (3s)
        if(Serial.available()>0){
          d2=Serial.readString();//lectura de la respuesta ingresada
          if(d2=="no"){//condicion para validar respuesta
            r2=1;//si la respuesta es correcta la calificacion es de un punto
            Serial.println(" Correcto");
          }else{
            Serial.println(" Incorrecto");
          }
        }
        Serial.println(" ");
      }
  
      //pregunta 3
      if(numero==2){
        Serial.println(p3);
        delay(3000);//Tiempo qe tiene el usuario para responder (3s)
        if(Serial.available()>0){
          d3=Serial.readString();
          if(d3=="no"){//Validacion de respuesta
            r3=1;//puntaje
            Serial.println(" Correcto");
          }else{
            Serial.println(" Incorrecto");
          }
        }
        Serial.println(" ");
      }
      //pregunta 4
      if(numero==3){
        Serial.println(p4);
        delay(3000);//Tiempo qe tiene el usuario para responder (3s)
        if(Serial.available()>0){
          d4=Serial.readString();//lectura de respuesta
          if(d4=="no"){//validacion de respuesta
            r4=1;//puntaje obtenido 
            Serial.println(" Correcto");
          }else{
            Serial.println(" Incorrecto");
          }
        }
        Serial.println(" ");
      }
      //pregunta 5
      if(numero==4){
        Serial.println(p5);
        delay(3000);//Tiempo qe tiene el usuario para responder (3s)
        if(Serial.available()>0){
          d5=Serial.readString();//lectura de respuesta
          if(d5=="si"){//validacion de respuesta
            r5=1;//puntaje de respuesta
            Serial.println(" Correcto");
          }else{
            Serial.println(" Incorrecto");
          }
        }
        Serial.println(" ");
      }
      
      //pregunta 6
      if(numero==5){
        Serial.println(p6);
        delay(3000);//Tiempo qe tiene el usuario para responder (3s)
        if(Serial.available()>0){
          d6=Serial.readString();//lectura de respuesta
          if(d6=="si"){//validacion de respuesta
            r6=1;//puntaje de respuesta
            Serial.println(" Correcto");
          }else{
            Serial.println(" Incorrecto");
          }
        }
        Serial.println(" ");
      }
      
      //pregunta 7
      if(numero==6){
        Serial.println(p7);
        delay(3000);//Tiempo qe tiene el usuario para responder (3s)
        if(Serial.available()>0){
          d7=Serial.readString();
          if(d7=="no"){
            r7=1;
            Serial.println(" Correcto");
          }else{
            Serial.println(" Incorrecto");
          }
        }
        Serial.println(" ");
      }
      //pregunta 8
      if(numero==7){
        Serial.println(p8);
        delay(3000);//Tiempo qe tiene el usuario para responder (3s)
        if(Serial.available()>0){
          d8=Serial.readString();
          if(d8=="no"){
            r8=1;
            Serial.println(" Correcto");
          }else{
            Serial.println(" Incorrecto");
          }
        }
        Serial.println(" ");
      }
    }
    puntaje=r1+r2+r3+r4+r5+r6+r7+r8;//Sumatoria del puntaje obtenido por cada pregunta
    Serial.println(String("Su puntaje es: ")+String(puntaje));
    
    //llamado del metodo para mostrar resultado en display
    mostrar();
    Serial.println(" ");
    Serial.println("Desea iniciar otra vez: ");
 
  }
  puntaje=0;
  //Reinicio del programa
  delay(3000);
  if(Serial.available()>0){
    String reinicio=Serial.readString();
    if(reinicio=="si" && puntaje==0){
      inicio =1;
      Serial.println(" ");
    }else{
    inicio=0;
    Serial.println(" ");
    Serial.println("Gracias");
    }
  }
  puntaje=0;
}

//Meetodo para mostrar puntaje en display
void mostrar(){
  if(puntaje==0){//si el puntaje obtenido es cero
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
  }
  if(puntaje==1){//si el puntaje obtenido es uno
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
  }
  if(puntaje==2){//si el puntaje obtenido es dos
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
  }
  if(puntaje==3){//si el puntaje obtenido es tres
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
  }
  if(puntaje==4){//si el puntaje obtenido es cuatro
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
  }
  if(puntaje==5){//si el puntaje obtenido es cinco
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
  }
  
}
