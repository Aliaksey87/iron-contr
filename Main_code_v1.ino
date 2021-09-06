#include <Wire.h>
#include <PID_v1.h>
#include "max6675.h"
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
LiquidCrystal_I2C _lcd1(0x27, 16, 2);
int _dispTempLength1=0;
boolean _isNeedClearDisp1;
MAX6675 MAX6675_16_17_15(17, 16, 15);
double _PID_1_Out=0.0;
double _PID_1_SP=0.0;
double _PID_1_In=0.0;
double _PID_1_Ki=0.0;
double _PID_1_Kp=0.0;
double _PID_1_Kd=0.0;
PID _PID_1(&_PID_1_In, &_PID_1_Out, &_PID_1_SP, 0, 0, 0, DIRECT);
unsigned long MAX6675_StTime;
bool MAX6675_CanPoll = 0;
const int _menuParametrsArray[]  PROGMEM =  {1, 3, 1, 0, 0, 0, 6, 7, 1, 8, 1, 0, 2, 8, 4, 0, 0, 0, 0, 0, 2, 0, 5, 0, 3, 8, 2, 0, 0, 0, 0, 0, 1, 0, 3, 0, 4, 8, 1, 0, 0, 0, 0, 0, 1, 0, 2, 0, 5, 8, 3, 0, 0, 0, 0, 0, 1, 0, 4, 0};
bool _menuValueArray_bool[1];
const bool _menuConstantValuesArray_bool[]  PROGMEM =  {1};
float _menuValueArray_float[4];
const float _menuConstantValuesArray_float[]  PROGMEM =  {10, 1};
const char _flprogMenuNameString1[] PROGMEM = "POWER ";
const char _flprogMenuNameString2[] PROGMEM = "Kd=";
const char _flprogMenuNameString3[] PROGMEM = "Kp=";
const char _flprogMenuNameString4[] PROGMEM = "Ki=";
const char _flprogMenuNameString5[] PROGMEM = " T=";
const char _flprogMenuNameString6[] PROGMEM = "ON ";
const char _flprogMenuNameString7[] PROGMEM = "OFF";
const char* const _flprogMenuStringsArray[] PROGMEM = { _flprogMenuNameString1,  _flprogMenuNameString2,  _flprogMenuNameString3,  _flprogMenuNameString4,  _flprogMenuNameString5,  _flprogMenuNameString6,  _flprogMenuNameString7};
struct _menuItemStricture 
{
     int startInArrayIndex;
}
;
struct _menuMainStricture 
{
    int startIndex;
    int stopIndex;
    bool isSwitchMenuAroundRing;
    _menuItemStricture  currentItem;
}
;
_menuItemStricture _MenuItems[5];
_menuMainStricture _MainMenus[1];
bool _gtv2 = 0;
bool _gtv3 = 0;
bool _tim5I = 0;
bool _tim5O = 0;
unsigned long _tim5P = 0UL;
int _disp34oldLength = 0;
bool _tim4I = 0;
bool _tim4O = 0;
unsigned long _tim4P = 0UL;
int _disp35oldLength = 0;
bool _tim3I = 0;
bool _tim3O = 0;
unsigned long _tim3P = 0UL;
unsigned long MAX6675_16_17_15_TT = 0UL;
float MAX6675_16_17_15_Output = 0.00;
bool _gen4I = 0;
bool _gen4O = 0;
unsigned long _gen4P = 0UL;
int _disp36oldLength = 0;
bool _bounseInputD4S = 0;
bool _bounseInputD4O = 0;
unsigned long _bounseInputD4P = 0UL;
bool _gen2I = 0;
bool _gen2O = 0;
unsigned long _gen2P = 0UL;
bool _bounseInputD3S = 0;
bool _bounseInputD3O = 0;
unsigned long _bounseInputD3P = 0UL;
bool _bounseInputD2S = 0;
bool _bounseInputD2O = 0;
unsigned long _bounseInputD2P = 0UL;
bool _PID_1_RelOut = 0;
unsigned long _PID_1_StartTime = 0UL;
int _disp39oldLength = 0;
String _MenuBlock_57698833_MNO;
String _MenuBlock_57698833_VNO;
bool _MenuBlock_57698833_OEIS = 0;
bool _MenuBlock_57698833_ORIS = 0;
bool _MenuBlock_57698833_OMUIS = 0;
bool _MenuBlock_57698833_OMDIS = 0;
bool _MenuBlock_57698833_OVUIS = 0;
bool _MenuBlock_57698833_OVDIS = 0;
unsigned long _MenuBlock_57698833_VUDST = 0UL;
unsigned long _MenuBlock_57698833_VUDSPT = 0UL;
int _MenuBlock_57698833_VUDSM = 0;
int _MenuBlock_57698833_VUDPT = 0;
bool _tim6I = 0;
bool _tim6O = 0;
unsigned long _tim6P = 0UL;
bool _D1B2 = 0;
bool _tim2I = 0;
bool _tim2O = 0;
unsigned long _tim2P = 0UL;
bool _trgrt1 = 0;
bool _trgrt1I = 0;
int _disp43oldLength = 0;
bool _gen3I = 0;
bool _gen3O = 0;
unsigned long _gen3P = 0UL;
bool _tim1I = 0;
bool _tim1O = 0;
unsigned long _tim1P = 0UL;
int _disp33oldLength = 0;
bool _tempVariable_bool;
unsigned long _tempVariable_unsignedlong;
int _tempVariable_int;
void setup()
{
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(6, OUTPUT);
    digitalWrite(6, 0);
    pinMode(13, OUTPUT);
    digitalWrite(13, 0);
    pinMode(5, OUTPUT);
    digitalWrite(5, 0);
    Wire.begin();
    delay(10);
    if(((readByteFromEEPROM(0, 0, 0x0))) != 233) 
    {
        (updateByteToEEPROM(0, 0, 0x0, (233)));
        (updateBooleanToEEPROM(1, 0, 0x0, (0)));
        (updateFloatToEEPROM(2, 0, 0x0, (2000)));
        (updateFloatToEEPROM(6, 0, 0x0, (1000)));
        (updateFloatToEEPROM(10, 0, 0x0, (1000)));
        (updateFloatToEEPROM(14, 0, 0x0, (250)));
    }
    MAX6675_StTime = millis();
    MAX6675_16_17_15_TT = millis() +500;
    _lcd1.init();
    _lcd1.noBacklight();
    _bounseInputD2O =  digitalRead(2);
    _bounseInputD3O =  digitalRead(3);
    _bounseInputD4O =  digitalRead(4);
    _MenuItems[0].startInArrayIndex = 0;
    _MenuItems[1].startInArrayIndex = 12;
    _MenuItems[2].startInArrayIndex = 24;
    _MenuItems[3].startInArrayIndex = 36;
    _MenuItems[4].startInArrayIndex = 48;
    _MainMenus[0].startIndex = 1;
    _MainMenus[0].isSwitchMenuAroundRing = 1;
    _MainMenus[0].stopIndex = 5;
    _MainMenus[0].currentItem = _MenuItems[0];
    _menuValueArray_bool[0] = (readBooleanFromEEPROM(1, 0, 0x0));
    _menuValueArray_float[0] = (readFloatFromEEPROM(2, 0, 0x0));
    _menuValueArray_float[1] = (readFloatFromEEPROM(6, 0, 0x0));
    _menuValueArray_float[2] = (readFloatFromEEPROM(10, 0, 0x0));
    _menuValueArray_float[3] = (readFloatFromEEPROM(14, 0, 0x0));
    _PID_1.SetOutputLimits(0, 100);
    _PID_1_StartTime = millis();
}
void loop()
{
    if (! MAX6675_CanPoll) 
    {
         MAX6675_CanPoll = _isTimer(MAX6675_StTime, 500);
    }
    if (_isNeedClearDisp1) 
    {
        _lcd1.clear();
        _isNeedClearDisp1= 0;
    }
    bool  _bounceInputTmpD4 =  (digitalRead (4));
    if (_bounseInputD4S)
    {
        if (millis() >= (_bounseInputD4P + 40))
        {
            _bounseInputD4O= _bounceInputTmpD4;
            _bounseInputD4S=0;
        }
    }
    else
    {
        if (_bounceInputTmpD4 != _bounseInputD4O)
        {
            _bounseInputD4S=1;
            _bounseInputD4P = millis();
        }
    }
    bool  _bounceInputTmpD2 =  (digitalRead (2));
    if (_bounseInputD2S)
    {
        if (millis() >= (_bounseInputD2P + 40))
        {
            _bounseInputD2O= _bounceInputTmpD2;
            _bounseInputD2S=0;
        }
    }
    else
    {
        if (_bounceInputTmpD2 != _bounseInputD2O)
        {
            _bounseInputD2S=1;
            _bounseInputD2P = millis();
        }
    }
    bool  _bounceInputTmpD3 =  (digitalRead (3));
    if (_bounseInputD3S)
    {
        if (millis() >= (_bounseInputD3P + 40))
        {
            _bounseInputD3O= _bounceInputTmpD3;
            _bounseInputD3S=0;
        }
    }
    else
    {
        if (_bounceInputTmpD3 != _bounseInputD3O)
        {
            _bounseInputD3S=1;
            _bounseInputD3P = millis();
        }
    }
    //Плата:2
    if (!(0))
    {
         if (_tim2I) 
        {
             if (_isTimer(_tim2P, 1)) 
            {
                _tim2O = 1;
            }
        }
         else 
        {
            _tim2I =1;
            _tim2P = millis();
        }
    }
     else 
    {
        _tim2O = 0;
        _tim2I = 0;
    }
    if (_tim2O) 
    {
        if (! _gen2I)
        {
            _gen2I = 1;
            _gen2O = 1;
            _gen2P = millis();
        }
    }
     else 
    {
        _gen2I = 0 ;
        _gen2O= 0;
    }
     if (_gen2I &&  _gen2O)   _gen2O = !(_isTimer(_gen2P , 1));
    if(_gen2O) 
    {
        _tim5O = 1;
        _tim5I = 1;
    }
     else 
    {
         if(_tim5I) 
        {
            _tim5I = 0;
            _tim5P = millis();
        }
         else 
        {
             if (_tim5O) 
            {
                if (_isTimer(_tim5P, 1500)) _tim5O = 0;
            }
        }
    }
    if (_tim5O) 
    {
        _dispTempLength1 = ((String("   gmail.com"))).length();
        if (_disp36oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp36oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 1);
        _lcd1.print((String("   gmail.com")));
    }
     else 
    {
        if (_disp36oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp36oldLength = 0;
        }
    }
    if (_tim5O) 
    {
        _dispTempLength1 = ((String(" atiunchyk.87@"))).length();
        if (_disp34oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp34oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 0);
        _lcd1.print((String(" atiunchyk.87@")));
    }
     else 
    {
        if (_disp34oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp34oldLength = 0;
        }
    }
    if (!(0))
    {
         if (_tim6I) 
        {
             if (_isTimer(_tim6P, 2000)) 
            {
                _tim6O = 1;
            }
        }
         else 
        {
            _tim6I =1;
            _tim6P = millis();
        }
    }
     else 
    {
        _tim6O = 0;
        _tim6I = 0;
    }
    if (_tim6O) 
    {
        if (! _gen3I)
        {
            _gen3I = 1;
            _gen3O = 1;
            _gen3P = millis();
        }
    }
     else 
    {
        _gen3I = 0 ;
        _gen3O= 0;
    }
     if (_gen3I &&  _gen3O)   _gen3O = !(_isTimer(_gen3P , 1));
    if(_gen3O) 
    {
        _tim3O = 1;
        _tim3I = 1;
    }
     else 
    {
         if(_tim3I) 
        {
            _tim3I = 0;
            _tim3P = millis();
        }
         else 
        {
             if (_tim3O) 
            {
                if (_isTimer(_tim3P, 1500)) _tim3O = 0;
            }
        }
    }
    if (_tim3O) 
    {
        _dispTempLength1 = ((String("sey87/iron-contr"))).length();
        if (_disp43oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp43oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 1);
        _lcd1.print((String("sey87/iron-contr")));
    }
     else 
    {
        if (_disp43oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp43oldLength = 0;
        }
    }
    if (_tim3O) 
    {
        _dispTempLength1 = ((String("github.com/Aliak"))).length();
        if (_disp33oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp33oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 0);
        _lcd1.print((String("github.com/Aliak")));
    }
     else 
    {
        if (_disp33oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp33oldLength = 0;
        }
    }
    if (!(0))
    {
         if (_tim4I) 
        {
             if (_isTimer(_tim4P, 4000)) 
            {
                _tim4O = 1;
            }
        }
         else 
        {
            _tim4I =1;
            _tim4P = millis();
        }
    }
     else 
    {
        _tim4O = 0;
        _tim4I = 0;
    }
    _gtv3 = _tim4O;
    if (!(0)) 
    {
        if (! _gen4I) 
        {
            _gen4I = 1;
            _gen4O = 1;
            _gen4P =  millis();
        }
    }
     else 
    {
        _gen4I = 0 ;
        _gen4O= 0;
    }
     if (_gen4I) 
    {
         if (_gen4O) 
        {
             if (_isTimer(_gen4P , 35)) 
            {
                 _gen4P = millis();
                _gen4O = 0;
            }
        }
         else  
        {
             if (_isTimer(_gen4P , 965)) 
            {
                  _gen4P = millis();
                _gen4O = 1;
            }
        }
    }
    digitalWrite(13, _gen4O);
    if(!(0)) 
    {
        if(! _D1B2)
        {
            _lcd1.backlight();
            _D1B2=1;
        }
    }
     else 
    {
        if(_D1B2)
        {
            _lcd1.noBacklight();
            _D1B2=0;
        }
    }
    if(((((!(_bounseInputD2O)) || (!(_bounseInputD3O)))) || (!(_bounseInputD4O)))) 
    {
        _tim1O = 1;
        _tim1I = 1;
    }
     else 
    {
         if(_tim1I) 
        {
            _tim1I = 0;
            _tim1P = millis();
        }
         else 
        {
             if (_tim1O) 
            {
                if (_isTimer(_tim1P, 5000)) _tim1O = 0;
            }
        }
    }
    if (!(_tim1O)) 
    {
         if (_trgrt1I) 
        {
             _trgrt1 = 0;
        }
         else 
        {
            _trgrt1 = 1;
            _trgrt1I = 1;
        }
    }
     else 
    {
        _trgrt1 = 0;
        _trgrt1I = 0;
    }
    ;
    _gtv2 = _trgrt1;
    if (!(0)) 
    {
        _tempVariable_bool  =  1;
        if (! _MenuBlock_57698833_OEIS) 
        {
            _MenuBlock_57698833_OEIS = 1;
        }
        _tempVariable_int = pgm_read_byte(&_menuParametrsArray[((_MainMenus[0].currentItem).startInArrayIndex)+10]);
        _MenuBlock_57698833_MNO = _readStringFromProgmem ((char*)pgm_read_word(&(_flprogMenuStringsArray[_tempVariable_int - 1])));
        _MenuBlock_57698833_VNO = _menuOutputValueString (0);
    }
     else 
    {
        _tempVariable_bool  =  0;
        if (_MenuBlock_57698833_OEIS)
        {
            _MenuBlock_57698833_OEIS = 0;
            _menuUpdateToEEpromItems();
        }
        _MenuBlock_57698833_MNO = "";
        _MenuBlock_57698833_VNO = "";
    }
    if(_gtv2) 
    {
         if (!_MenuBlock_57698833_ORIS) 
        {
            _MenuBlock_57698833_ORIS = 1;
            if(_tempVariable_bool)
            {
                _MainMenus[0].currentItem = _MenuItems[0];
                _menuUpdateToEEpromItems();
            }
        }
    }
     else 
    {
        _MenuBlock_57698833_ORIS = 0;
    }
    if(0) 
    {
         if (! _MenuBlock_57698833_OMUIS) 
        {
            _MenuBlock_57698833_OMUIS = 1;
            if(_tempVariable_bool)
            {
                _menuUpEvents(0);
                _menuUpdateToEEpromItems();
            }
        }
    }
     else 
    {
        _MenuBlock_57698833_OMUIS = 0;
    }
    if(!(_bounseInputD2O)) 
    {
         if (! _MenuBlock_57698833_OMDIS) 
        {
            _MenuBlock_57698833_OMDIS = 1;
            if(_tempVariable_bool)
            {
                _menuDownEvents(0);
                _menuUpdateToEEpromItems();
            }
        }
    }
     else 
    {
        _MenuBlock_57698833_OMDIS = 0;
    }
    if(!(_bounseInputD3O)) 
    {
         if (! _MenuBlock_57698833_OVUIS) 
        {
            _MenuBlock_57698833_OVUIS = 1;
            if(_tempVariable_bool)
            {
                  _valueUpEvents(0);
                _MenuBlock_57698833_VUDST = millis();
            }
        }
        if (_tempVariable_bool)
        {
            if (_MenuBlock_57698833_VUDSM == 0) 
            {
                 if (_isTimer(_MenuBlock_57698833_VUDST , 1000)) 
                {
                    _MenuBlock_57698833_VUDSM = 1;
                    _MenuBlock_57698833_VUDSPT = millis();
                    _MenuBlock_57698833_VUDPT  = 250;
                }
            }
              else 
            {
                 if (_MenuBlock_57698833_VUDSM == 1) 
                {
                     if (_isTimer(_MenuBlock_57698833_VUDST , 2000)) 
                    {
                        _MenuBlock_57698833_VUDSM = 2;
                        _MenuBlock_57698833_VUDPT  = 125;
                    }
                }
                 if (_isTimer(_MenuBlock_57698833_VUDSPT , _MenuBlock_57698833_VUDPT)) 
                {
                     _valueUpEvents(0);
                    _MenuBlock_57698833_VUDSPT = millis();
                }
            }
        }
    }
     else 
    {
        _MenuBlock_57698833_OVUIS = 0;
        if(! (!(_bounseInputD4O)))
        {
            _MenuBlock_57698833_VUDSM = 0;
        }
    }
    if(!(_bounseInputD4O)) 
    {
         if (! _MenuBlock_57698833_OVDIS) 
        {
            _MenuBlock_57698833_OVDIS = 1;
            if(_tempVariable_bool)
            {
                  _valueDownEvents(0);
                _MenuBlock_57698833_VUDST = millis();
            }
        }
         if (_tempVariable_bool)
        {
            if (_MenuBlock_57698833_VUDSM == 0) 
            {
                 if (_isTimer(_MenuBlock_57698833_VUDST , 1000)) 
                {
                    _MenuBlock_57698833_VUDSM = 1;
                    _MenuBlock_57698833_VUDSPT = millis();
                    _MenuBlock_57698833_VUDPT  = 250;
                }
            }
              else 
            {
                 if (_MenuBlock_57698833_VUDSM == 1) 
                {
                     if (_isTimer(_MenuBlock_57698833_VUDST , 2000)) 
                    {
                        _MenuBlock_57698833_VUDSM = 2;
                        _MenuBlock_57698833_VUDPT  = 125;
                    }
                }
                 if (_isTimer(_MenuBlock_57698833_VUDSPT , _MenuBlock_57698833_VUDPT)) 
                {
                     _valueDownEvents(0);
                    _MenuBlock_57698833_VUDSPT = millis();
                }
            }
        }
    }
     else 
    {
        _MenuBlock_57698833_OVDIS = 0;
        if(! (!(_bounseInputD3O)))
        {
            _MenuBlock_57698833_VUDSM = 0;
        }
    }
    if (_isTimer(MAX6675_16_17_15_TT, 500)) 
    {
        MAX6675_16_17_15_TT = millis();
        if(MAX6675_CanPoll) 
        {
            MAX6675_16_17_15_Output = MAX6675_16_17_15.readCelsius();
        }
    }
    _tempVariable_bool = (_menuValueArray_bool[0]);
    if(!((_PID_1.GetMode()) == _tempVariable_bool)) 
    {
        _PID_1.SetMode(_tempVariable_bool);
    }
    if(! _tempVariable_bool) 
    {
        _PID_1_Out = 0;
    }
    _tempVariable_int = 1000.00;
    _PID_1.SetSampleTime(_tempVariable_int);
    _PID_1_Kd = (_menuValueArray_float[0]);
    _PID_1_Kp = (_menuValueArray_float[1]);
    _PID_1_Ki = (_menuValueArray_float[2]);
    _PID_1.SetTunings(_PID_1_Kp, _PID_1_Ki, _PID_1_Kd);
    _PID_1_In = MAX6675_16_17_15_Output;
    _PID_1_SP = (_menuValueArray_float[3]);
    _PID_1.Compute();
    _tempVariable_unsignedlong = millis();
    if(_tempVariable_unsignedlong - _PID_1_StartTime>100) 
    {
        _PID_1_StartTime += 100;
    }
    if(_PID_1_Out > _tempVariable_unsignedlong - _PID_1_StartTime) 
    {
        _PID_1_RelOut = 1;
    }
      else 
    {
        _PID_1_RelOut = 0;
    }
    digitalWrite(5, _PID_1_RelOut);
    digitalWrite(6, _PID_1_RelOut);
    if (_gtv3) 
    {
        _dispTempLength1 = ((((String("")) + ((String((int(MAX6675_16_17_15_Output)), DEC))) + (String("C -> ")) + ((_floatToStringWitRaz((_menuValueArray_float[3]),0))) + (String("C"))))).length();
        if (_disp39oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp39oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 1);
        _lcd1.print((((String("")) + ((String((int(MAX6675_16_17_15_Output)), DEC))) + (String("C -> ")) + ((_floatToStringWitRaz((_menuValueArray_float[3]),0))) + (String("C")))));
    }
     else 
    {
        if (_disp39oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp39oldLength = 0;
        }
    }
    if (_gtv3) 
    {
        _dispTempLength1 = ((((_MenuBlock_57698833_MNO) + (String("")) + (_MenuBlock_57698833_VNO) + (String("")) + (String(""))))).length();
        if (_disp35oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp35oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 0);
        _lcd1.print((((_MenuBlock_57698833_MNO) + (String("")) + (_MenuBlock_57698833_VNO) + (String("")) + (String("")))));
    }
     else 
    {
        if (_disp35oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp35oldLength = 0;
        }
    }
}
String  _floatToStringWitRaz(float value, int raz)
{
    return String(value,raz);
}
bool _isTimer(unsigned long startTime, unsigned long period)
{
    unsigned long currentTime;
    currentTime = millis();
    if (currentTime>= startTime) 
    {
        return (currentTime>=(startTime + period));
    }
     else 
    {
        return (currentTime >=(4294967295-startTime+period));
    }
}
String _readStringFromProgmem (char *string)
{
    String result = String("");
    while (pgm_read_byte(string)!='\0')
    {
        result=result+ char(pgm_read_byte(string));
        	string++;
        	
    }
    return result;
}
void _menuUpEvents (int menuIndex)
{
    int tempIndex = pgm_read_byte(&_menuParametrsArray[((_MainMenus[menuIndex]).currentItem).startInArrayIndex]);
    int parIndex = pgm_read_byte(&_menuParametrsArray[ (((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+5]);
    int parentStartIndex;
    int parentStopIndex;
    if (parIndex == 0) 
    {
        parentStartIndex = (_MainMenus[menuIndex]).startIndex;
        parentStopIndex =(_MainMenus[menuIndex]).stopIndex;
    }
    else 
    {
        parentStartIndex = pgm_read_byte(&_menuParametrsArray[((_MenuItems[parIndex - 1]).startInArrayIndex)+3]);
        parentStopIndex = pgm_read_byte(&_menuParametrsArray[((_MenuItems[parIndex-1]).startInArrayIndex)+4]);
    }
    if (tempIndex == parentStartIndex) 
    {
        if((_MainMenus[menuIndex]).isSwitchMenuAroundRing) 
        {
            (_MainMenus[menuIndex]).currentItem = _MenuItems[parentStopIndex -1];
            return;
        }
         else
        {
            return;
        }
    }
    (_MainMenus[menuIndex]).currentItem = _MenuItems[tempIndex - 2];
    return;
}
void _menuDownEvents (int menuIndex)
{
    int tempIndex = pgm_read_byte(&_menuParametrsArray[((_MainMenus[menuIndex]).currentItem).startInArrayIndex]);
    int parIndex = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+5]);
    int parentStartIndex;
    int parentStopIndex;
    if (parIndex == 0) 
    {
        parentStartIndex = (_MainMenus[menuIndex]).startIndex;
        parentStopIndex =(_MainMenus[menuIndex]).stopIndex;
    }
    else 
    {
        parentStartIndex = pgm_read_byte(&_menuParametrsArray[((_MenuItems[parIndex-1]).startInArrayIndex)+3]);
        parentStopIndex = pgm_read_byte(&_menuParametrsArray[((_MenuItems[parIndex-1]).startInArrayIndex)+4]);
    }
    if (tempIndex == parentStopIndex) 
    {
        if((_MainMenus[menuIndex]).isSwitchMenuAroundRing) 
        {
            (_MainMenus[menuIndex]).currentItem = _MenuItems[parentStartIndex -1];
            return;
        }
         else
        {
            return;
        }
    }
    (_MainMenus[menuIndex]).currentItem = _MenuItems[tempIndex];
    return;
}
void _valueUpEvents (int menuIndex)
{
    int valIndex = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+2]);
    int itemType = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+1]);
    int indexMax = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+6]);
    int indexStep = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+8]);
    if(itemType ==3) 
    {
        _menuValueArray_bool[valIndex - 1 ] = 1;
        return;
    }
    if (itemType == 8) 
    {
        _menuValueArray_float[valIndex -1] = _menuValueArray_float[valIndex -1] + (pgm_read_float(&_menuConstantValuesArray_float[indexStep -1]));
    }
}
void _valueDownEvents (int menuIndex)
{
    int valIndex = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+2]);
    int itemType = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+1]);
    int indexMin = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+7]);
    int indexStep = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+8]);
    if(itemType ==3) 
    {
        _menuValueArray_bool[valIndex -1] = 0;
        return;
    }
    if (itemType == 8) 
    {
        _menuValueArray_float[valIndex - 1] = _menuValueArray_float[valIndex - 1] - (pgm_read_float(&_menuConstantValuesArray_float[indexStep - 1]));
    }
}
String _menuOutputValueString (int menuIndex)
{
    int itemType = pgm_read_byte(&_menuParametrsArray[ (((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+1]);
    int valIndex = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+2]);
    int indexMin = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+7]);
    int indexMax = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+6]);
    if(valIndex == 0)
    {
         return "";
    }
    int convFormat = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+9]);
    if(itemType == 3) 
    {
         return _convertBoolean(itemType, convFormat, valIndex, indexMax, indexMin);
    }
    if(itemType == 8) 
    {
         return _convertFloat(itemType, convFormat, valIndex, indexMax, indexMin);
    }
    return "";
}
void _menuUpdateToEEpromItems()
{
    (updateBooleanToEEPROM(1, 0, 0x0, ((_menuValueArray_bool[0]))));
    (updateFloatToEEPROM(2, 0, 0x0, ((_menuValueArray_float[0]))));
    (updateFloatToEEPROM(6, 0, 0x0, ((_menuValueArray_float[1]))));
    (updateFloatToEEPROM(10, 0, 0x0, ((_menuValueArray_float[2]))));
    (updateFloatToEEPROM(14, 0, 0x0, ((_menuValueArray_float[3]))));
}
String _convertNamber(int itemType, int convFormat, int valIndex, int indexMax, int indexMin)
{
    if (itemType== 8) 
    {
        if (convFormat == 4) 
        {
             return String((_menuValueArray_float[valIndex - 1 ]),DEC);
        }
        if (convFormat == 5) 
        {
             return String((_menuValueArray_float[valIndex - 1]),HEX);
        }
        if (convFormat == 6) 
        {
             return String((_menuValueArray_float[valIndex -1]),BIN);
        }
    }
}
String _convertBoolean(int itemType, int convFormat, int valIndex, int indexMax, int indexMin)
{
    if (convFormat == 1) 
    {
         if(_menuValueArray_bool[valIndex -1]) 
        {
            return "1";
        }
         else
        {
             return "0";
        }
    }
    if (convFormat == 2) 
    {
         if(_menuValueArray_bool[valIndex -1]) 
        {
            return "True";
        }
         else
        {
             return "False";
        }
    }
    if (convFormat == 3) 
    {
         if(_menuValueArray_bool[valIndex -1 ]) 
        {
            return "Да";
        }
         else
        {
             return "Нет";
        }
    }
    if(_menuValueArray_bool[valIndex -1]) 
    {
        return _readStringFromProgmem ((char*)pgm_read_word(&(_flprogMenuStringsArray[indexMax - 1])));
    }
     else 
    {
         return _readStringFromProgmem ((char*)pgm_read_word(&(_flprogMenuStringsArray[indexMin - 1])));
    }
}
String _convertFloat(int itemType, int convFormat, int valIndex , int indexMax, int indexMin)
{
    return String((_menuValueArray_float[valIndex -1]),convFormat);
}
byte readByteFromEEPROM(int addres, byte bitAddres, byte chipAddres)
{
    return EEPROM.read(addres);
}
void updateByteToEEPROM(int addres, byte bitAddres, byte chipAddres, byte value)
{
    return EEPROM.update(addres, value);
}
bool readBooleanFromEEPROM(int addres, byte bitAddres, byte chipAddres)
{
    byte temp = readByteFromEEPROM(addres,  bitAddres,  chipAddres);
    return  bitRead(temp, bitAddres);
}
void updateBooleanToEEPROM(int addres, byte bitAddres, byte chipAddres, bool value)
{
    byte temp = readByteFromEEPROM(addres,  bitAddres,  chipAddres);
    bitWrite(temp, bitAddres, value);
    updateByteToEEPROM(addres,  bitAddres,  chipAddres, temp);
}
float readFloatFromEEPROM(int addres, byte bitAddres, byte chipAddres)
{
    byte x[4];
    for(byte i = 0; i < 4; i++) 
    {
         x[i] = readByteFromEEPROM((addres+i),  bitAddres,  chipAddres);
    }
    float *y = (float *)&x;
    return y[0];
}
void updateFloatToEEPROM(int addres, byte bitAddres, byte chipAddres, float value)
{
    byte *x = (byte *)&value;
    for(byte i = 0; i < 4; i++) 
    {
        updateByteToEEPROM((addres+i),  bitAddres,  chipAddres, x[i]);
    }
}
