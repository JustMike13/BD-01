class BuzzerControl 
{
    int buzzerPin;
public:
    void Set(int bp)
    {
        buzzerPin = bp;
        pinMode(buzzerPin, OUTPUT);
    }

    void Beep()
    {
        Serial.println("test audio" + buzzerPin);
        int d2;
        int k = random(3, 6);
        for (int i = 0; i <= k; i++)
        {
            int l = random(-1700, 1000);
            int d1 = random(70, 170);
            d2 = random(0, 30);
            tone(buzzerPin, 3000 + l);          
            delay(d1);        
            noTone(buzzerPin);         
            delay(d2);             
        } 
        
        noTone(buzzerPin);
    }

    void Beep2(int newTone)
    {
        if (newTone < 0)
            noTone(buzzerPin);
        else
            tone(buzzerPin, newTone);
    }

    int getPin(){
        return buzzerPin;
    }

};

