/*
  Sino da Escola sincronizada com o relógio núclear dos satelítes de GPS
  Desenvolvido por Nilson Santos "nilsonccl@gmail.com"
  com base na biblíoteca "TinyGPS" e "LiquidCrystal"
  Fernando de Noronha - PE - Brasil
*/

#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>


TinyGPS shield;  // Cria uma instância sobre um objeto da biblíoteca "TinyGPS"
SoftwareSerial GPS(2,3); // configure a porta "software serial" 
LiquidCrystal lcd(8, 10, 9, 4, 5, 6, 7);  // Configuração da ligação do LCD

byte sino[8] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B00100,
  B00000,
};

void setup()
{
  //Mostra uma mensagem quando liga
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Carregando...");
  lcd.setCursor(0,1);
  lcd.print("\xFF");
  delay(500);
  lcd.print("\xFF");
  delay(500);
  lcd.print("\xFF");
  delay(500);
  lcd.print("\xFF");
  delay(500);
  lcd.print("\xFF");
  delay(250);
  lcd.print("\xFF");
  delay(250);
  lcd.print("\xFF");
  delay(125);
  lcd.print("\xFF");
  delay(125);
  lcd.print("\xFF");
  delay(125);
  lcd.print("\xFF");
  delay(125);
  lcd.print("\xFF");
  delay(125);
  lcd.print("\xFF");
  delay(125);
  lcd.print("\xFF");
  delay(125);
  lcd.print("\xFF");
  delay(125);
  lcd.print("\xFF");
  delay(500);
  lcd.print("\xFF");
  GPS.begin(9600);
  delay(1000);
  lcd.clear();
}

// A função "getgps" irá interpretar dados do GPS e exibir no monitor serial
void getgps(TinyGPS &gps)
{
  int year;
  byte month, day, hour, minute, second, hundredths;
  shield.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);
 
 //Correção de fuso-horario
  hour = hour - 2;
  if (hour=2)
  {
    (hour=22);
  }
  if (hour=1)
  {
    (hour=23);
  }
  if (hour>=22)
  {
    (day = day - 1);
  }
 

  // Mostra Hora
  lcd.createChar(0, sino);
  lcd.setCursor(0,0);
  lcd.print("Hora: ");
  if (hour<10)
  {
    lcd.print("0");
    lcd.print(hour, DEC);
  } 
  else if (hour>=10)
  {
    lcd.print(hour, DEC);
  }
  lcd.print(":");
  if (minute<10)
  {
    lcd.print("0");
    lcd.print(minute, DEC);
  } 
  else if (minute>=10)
  {
    lcd.print(minute, DEC);
  }
  lcd.print(":");
  if (second<10)
  {
    lcd.print("0");
    lcd.print(second, DEC);
  } 
  else if (second>=10)
  {
    lcd.print(second, DEC);
  }
  
  //Alarme de "Entrada às 7:30"
  if (hour==7)                 //Hora do alarme
  {
    if (minute==30)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}
  //Alarme de "Intervalo às 9:30"
  if (hour==9)                //Hora do alarme
  {
    if (minute==30)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}
  //Alarme de "Retorno do Intervalo às 10:00"
  if (hour==10)                //Hora do alarme
  {
    if (minute==0)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}
  //Alarme de "Saída às 12:00"
  if (hour==12)                //Hora do alarme
  {
    if (minute==0)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Turno da Trarde

  //Alarme de "1ª aula às 13:10"
  if (hour==13)                //Hora do alarme
  {
    if (minute==10)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme de "2ª aula às 14:00"
  if (hour==14)                //Hora do alarme
  {
    if (minute==0)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme da "3ª aula às 14:50"
  if (hour==14)                //Hora do alarme
  {
    if (minute==50)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme do "Intervalo às 15:40"
  if (hour==15)                //Hora do alarme
  {
    if (minute==40)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme de "Retorno do Intervalo às 16:00"
  if (hour==16)                //Hora do alarme
  {
    if (minute==0)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme de "4ª aula às 16:50"
  if (hour==16)                //Hora do alarme
  {
    if (minute==50)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme de "Saída às 17:40"
  if (hour==17)                //Hora do alarme
  {
    if (minute==40)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Horários Noturnos
 
  //Alarme de "1ª aula às 18:40"
  if (hour==18)                //Hora do alarme
  {
    if (minute==40)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme de "2ª aula às 19:20"
  if (hour==19)                //Hora do alarme
  {
    if (minute==20)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme da "3ª aula às 20:00"
  if (hour==20)                //Hora do alarme
  {
    if (minute==0)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme do "Intervalo às 20:40"
  if (hour==20)                //Hora do alarme
  {
    if (minute==40)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme de "Retorno do Intervalo às 20:45"
  if (hour==20)                //Hora do alarme
  {
    if (minute==45)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme de "4ª aula às 21:20"
  if (hour==21)                //Hora do alarme
  {
    if (minute==20)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  //Alarme de "Saída às 22:00"
  if (hour==22)                //Hora do alarme
  {
    if (minute==0)            //Minuto do alarme
    {
    if (second<5)
    {
      digitalWrite(13, HIGH);
    } 
    else if (second>5)
    {
      digitalWrite(13, LOW);
    }
  }
}

  // Mostra Data
  lcd.setCursor(0,1);
  lcd.print("Data: ");  
    if (day<10)
  {
    lcd.print("0");
    lcd.print(day, DEC);
  } 
  else if (day>=10)
  {
    lcd.print(day, DEC);
  }
  lcd.print("/");
    if (month<10)
  {
    lcd.print("0");
    lcd.print(month, DEC);
  } 
  else if (month>=10)
  {
    lcd.print(month, DEC);
  }
  lcd.print("/");
  lcd.print(year, DEC);  

  //Mostrar mensagem
  if (second==10)            //Segundo da Mensagem
  {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    School");
      lcd.setCursor(0,1);
      lcd.print("     Bell");
      delay(3990);
      lcd.clear();
   }
}

void loop()
{
  byte a;
  if ( GPS.available() > 0 ) // se houver dados provenientes do GPS
  {
    a = GPS.read();          // obter o byte de dados
    if(shield.encode(a))     // se houver dados válidos GPS...
    {
      getgps(shield);        // em seguida, pegue os dados e exibi-lo na tela LCD
    }
  }  
}
