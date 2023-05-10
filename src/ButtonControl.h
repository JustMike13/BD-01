class ButtonControl
{
    int buttonPin;
    int butVal;
    int oldVal;
public:
    void Set(int bp)
    {
        buttonPin = bp;
        pinMode(buttonPin, INPUT_PULLUP);
        butVal = HIGH;
        oldVal = HIGH;
    }

    bool ButtonPressed()
    {
        butVal = digitalRead(buttonPin);
        bool retV = false;
        if (butVal == LOW && butVal != oldVal)
        {
            retV = true;
        }
        oldVal = butVal;
        return retV;
    }
};