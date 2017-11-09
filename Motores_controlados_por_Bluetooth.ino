int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10; 
int vel = 255;            // Velocidad de los motores (0-255)
int estado = 'g';         // inicia detenido

void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
 } 
 
void loop()  { 
  
  if(Serial.available()>0){        // lee el bluetooth y almacena en estado
      estado = Serial.read();
      Serial.print( "dato" );
      Serial.println( estado );
  }
  if(estado=='A'){           // Boton desplazar al Frente
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, vel);  
      analogWrite(izqA, vel);       
  }
  if(estado=='B'){          // Boton IZQ 
       analogWrite(derB, vel);     
       analogWrite(izqB, 0);
       analogWrite(izqA, 0);
       analogWrite(derA, 0); ;      
  }
  if(estado=='C'){         // Boton Parar
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);    
      analogWrite(izqA, 0); 
  }
  if(estado=='D'){          // Boton DER
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, vel);
       analogWrite(derA, 0);  
  } 
  
  if(estado=='E'){          // Boton Reversa
      analogWrite(derB, vel);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);  
      analogWrite(izqA, vel);     
  }
  if (estado =='F'){          
 
  }
  if  (estado=='G'){          
  }
}
