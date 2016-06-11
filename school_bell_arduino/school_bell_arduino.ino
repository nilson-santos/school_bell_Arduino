/*
  Bell School synchronized with the nuclear clock of GPS satellites
  based on the library " TinyGPS ","SoftwareSerial" and "LiquidCrystal"
  Brazil
*/

#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>


TinyGPS shield;  // It creates an instance of an object from the library "TinyGPS"
SoftwareSerial GPS(2,3); // configure the port "Software Serial"
LiquidCrystal lcd(8, 10, 9, 4, 5, 6, 7);  // LCD connection setup

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
  //Displays a message when you power on
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

// The " getgps " will interpret GPS data and display the serial monitor
void getgps(TinyGPS &gps)
{
  int year;
  byte month, day, hour, minute, second, hundredths;
  shield.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);
 
 //Correction time - schedule
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
 

  // Time shows
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
  
  //Bell "Entrance at 7:30 am"
  if (hour==7)                 //bell time
  {
    if (minute==30)            //bell Minute
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
  //Bell "Interval at 9:30 am"
  if (hour==9)                //bell time
  {
    if (minute==30)            //bell Minute
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
  //Bell "Interval Return at 10:00 am"
  if (hour==10)                //bell time
  {
    if (minute==0)            //bell Minute
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
  //Bell "Check out at 12:00 pm"
  if (hour==12)                //bell time
  {
    if (minute==0)            //bell Minute
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

  //Afternoon shift

  //Bell "1st class at 1:10 pm"
  if (hour==13)                //bell time
  {
    if (minute==10)            //bell Minute
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

  //Bell "2nd class at 2:00 pm"
  if (hour==14)                //bell time
  {
    if (minute==0)            //bell Minute
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

  //Bell "3rd class at 2:50 pm"
  if (hour==14)                //bell time
  {
    if (minute==50)            //bell Minute
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

  //Bell "Interval at 3:40 pm"
  if (hour==15)                //bell time
  {
    if (minute==40)            //bell Minute
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

  //Bell "Interval Return at 4:00 pm"
  if (hour==16)                //bell time
  {
    if (minute==0)            //bell Minute
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

  //Bell "4th class at 4:50 pm"
  if (hour==16)                //bell time
  {
    if (minute==50)            //bell Minute
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

  //Bell "Check out at 5:40 pm"
  if (hour==17)                //bell time
  {
    if (minute==40)            //bell Minute
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

  //Night shift
 
  //Bell "1st class at 6:40 pm"
  if (hour==18)                //bell time
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

  //Bell "2nd class at 7:20 pm"
  if (hour==19)                //bell time
  {
    if (minute==20)            //bell Minute
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

  //Bell "3rd class at 8:00 pm"
  if (hour==20)                //bell time
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

  //Bell "Interval at 8:40 pm"
  if (hour==20)                //bell time
  {
    if (minute==40)            //bell Minute
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

  //Bell "Interval Return at 8:45 pm"
  if (hour==20)                //bell time
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

  //Bell "4th class at 9:20 pm"
  if (hour==21)                //bell time
  {
    if (minute==20)            //bell Minute
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

  //Bell "Check out at 10:00 pm"
  if (hour==22)                //bell time
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

  // Shows Date
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

  //shows a message
  if (second==10)            //second showing message
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
  if ( GPS.available() > 0 ) // if data from the GPS
  {
    a = GPS.read();          // to obtain the data byte
    if(shield.encode(a))     // if GPS valid data ...
    {
      getgps(shield);        // then take the data and display it on the LCD screen
    }
  }  
}
