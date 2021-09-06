
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C _lcd1(0x27, 16, 2);
int _dispTempLength1=0;
boolean _isNeedClearDisp1;

bool _gtv1 = 0;
int _disp7oldLength = 0;
int _disp2oldLength = 0;
bool _dms1Q0 = 0;
bool _dms1Q1 = 0;
bool _dms1Q2 = 0;
bool _dms1Q3 = 0;
bool _dms1Q4 = 0;
bool _dms1Q5 = 0;
bool _dms1Q6 = 0;
bool _dms1Q7 = 0;
bool _dms1Q8 = 0;
bool _dms1Q9 = 0;
bool _dms1Q10 = 0;
bool _dms1Q11 = 0;
bool _dms1Q12 = 0;
bool _dms1Q13 = 0;
bool _dms1Q14 = 0;
bool _dms1Q15 = 0;
bool _dms1Q16 = 0;
bool _dms1Q17 = 0;
bool _dms1Q18 = 0;
bool _dms1Q19 = 0;
bool _dms1Q20 = 0;
bool _dms1Q21 = 0;
bool _dms1Q22 = 0;
bool _dms1Q23 = 0;
bool _dms1Q24 = 0;
bool _dms1Q25 = 0;
bool _dms1Q26 = 0;
bool _dms1Q27 = 0;
bool _dms1Q28 = 0;
bool _dms1Q29 = 0;
bool _dms1Q30 = 0;
bool _dms1Q31 = 0;
bool _dms1Q32 = 0;
int _disp32oldLength = 0;
int _disp27oldLength = 0;
int _disp22oldLength = 0;
int _disp31oldLength = 0;
int _disp17oldLength = 0;
int _disp26oldLength = 0;
int _disp12oldLength = 0;
int _disp21oldLength = 0;
int _disp16oldLength = 0;
int _disp11oldLength = 0;
int _disp20oldLength = 0;
int _disp6oldLength = 0;
int _disp15oldLength = 0;
bool _gen1I = 0;
bool _gen1O = 0;
unsigned long _gen1P = 0UL;
int _disp10oldLength = 0;
int _disp5oldLength = 0;
bool _count1I = 0;
int _count1_Value = 0;
bool _count1MaxLO = 0;
int _disp30oldLength = 0;
int _disp25oldLength = 0;
int _disp29oldLength = 0;
bool _D1B1 = 0;
int _disp24oldLength = 0;
int _disp19oldLength = 0;
int _disp28oldLength = 0;
int _disp14oldLength = 0;
int _disp23oldLength = 0;
int _disp9oldLength = 0;
int _disp18oldLength = 0;
int _disp4oldLength = 0;
int _disp13oldLength = 0;
int _disp1oldLength = 0;
int _disp8oldLength = 0;
int _disp3oldLength = 0;

void setup()
{

Wire.begin();
delay(10);
_lcd1.init();
_lcd1.noBacklight();

}
void loop()
{

if (_isNeedClearDisp1) {_lcd1.clear(); _isNeedClearDisp1= 0;}





//Плата:1
if(!(0)) {if(! _D1B1){_lcd1.backlight(); _D1B1=1; }} else {if(_D1B1){_lcd1.noBacklight(); _D1B1=0; }}
if (!(0)) { if (! _gen1I) { _gen1I = 1; _gen1O = 1; _gen1P = millis(); } } else { _gen1I = 0 ; _gen1O= 0;}
 if (_gen1I) {  if ( _isTimer ( _gen1P , 100 )) { _gen1P = millis(); _gen1O = ! _gen1O;}}
if (0){
_count1_Value = 0;
} else {
if (_gtv1){_count1_Value = 0;} else {
if (_gen1O){
if ( ! _count1I) { 
_count1I = 1;
_count1_Value = _count1_Value + 1;
}} else {
_count1I = 0;}
}
}
_count1MaxLO = _count1_Value >= 33; 
if((_count1_Value == 0)){_dms1Q0 = 1;}else {_dms1Q0 = 0;}
if((_count1_Value == 1)){_dms1Q1 = 1;}else {_dms1Q1 = 0;}
if((_count1_Value == 2)){_dms1Q2 = 1;}else {_dms1Q2 = 0;}
if((_count1_Value == 3)){_dms1Q3 = 1;}else {_dms1Q3 = 0;}
if((_count1_Value == 4)){_dms1Q4 = 1;}else {_dms1Q4 = 0;}
if((_count1_Value == 5)){_dms1Q5 = 1;}else {_dms1Q5 = 0;}
if((_count1_Value == 6)){_dms1Q6 = 1;}else {_dms1Q6 = 0;}
if((_count1_Value == 7)){_dms1Q7 = 1;}else {_dms1Q7 = 0;}
if((_count1_Value == 8)){_dms1Q8 = 1;}else {_dms1Q8 = 0;}
if((_count1_Value == 9)){_dms1Q9 = 1;}else {_dms1Q9 = 0;}
if((_count1_Value == 10)){_dms1Q10 = 1;}else {_dms1Q10 = 0;}
if((_count1_Value == 11)){_dms1Q11 = 1;}else {_dms1Q11 = 0;}
if((_count1_Value == 12)){_dms1Q12 = 1;}else {_dms1Q12 = 0;}
if((_count1_Value == 13)){_dms1Q13 = 1;}else {_dms1Q13 = 0;}
if((_count1_Value == 14)){_dms1Q14 = 1;}else {_dms1Q14 = 0;}
if((_count1_Value == 15)){_dms1Q15 = 1;}else {_dms1Q15 = 0;}
if((_count1_Value == 16)){_dms1Q16 = 1;}else {_dms1Q16 = 0;}
if((_count1_Value == 17)){_dms1Q17 = 1;}else {_dms1Q17 = 0;}
if((_count1_Value == 18)){_dms1Q18 = 1;}else {_dms1Q18 = 0;}
if((_count1_Value == 19)){_dms1Q19 = 1;}else {_dms1Q19 = 0;}
if((_count1_Value == 20)){_dms1Q20 = 1;}else {_dms1Q20 = 0;}
if((_count1_Value == 21)){_dms1Q21 = 1;}else {_dms1Q21 = 0;}
if((_count1_Value == 22)){_dms1Q22 = 1;}else {_dms1Q22 = 0;}
if((_count1_Value == 23)){_dms1Q23 = 1;}else {_dms1Q23 = 0;}
if((_count1_Value == 24)){_dms1Q24 = 1;}else {_dms1Q24 = 0;}
if((_count1_Value == 25)){_dms1Q25 = 1;}else {_dms1Q25 = 0;}
if((_count1_Value == 26)){_dms1Q26 = 1;}else {_dms1Q26 = 0;}
if((_count1_Value == 27)){_dms1Q27 = 1;}else {_dms1Q27 = 0;}
if((_count1_Value == 28)){_dms1Q28 = 1;}else {_dms1Q28 = 0;}
if((_count1_Value == 29)){_dms1Q29 = 1;}else {_dms1Q29 = 0;}
if((_count1_Value == 30)){_dms1Q30 = 1;}else {_dms1Q30 = 0;}
if((_count1_Value == 31)){_dms1Q31 = 1;}else {_dms1Q31 = 0;}
if((_count1_Value == 32)){_dms1Q32 = 1;}else {_dms1Q32 = 0;}
if (_dms1Q32) {
_dispTempLength1 = ((String("*"))).length();
if (_disp32oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp32oldLength = _dispTempLength1;
_lcd1.setCursor(15, 1);
_lcd1.print((String("*")));
} else {
if (_disp32oldLength > 0) {_isNeedClearDisp1 = 1; _disp32oldLength = 0;} 
}
if (_dms1Q31) {
_dispTempLength1 = ((String("*"))).length();
if (_disp31oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp31oldLength = _dispTempLength1;
_lcd1.setCursor(14, 1);
_lcd1.print((String("*")));
} else {
if (_disp31oldLength > 0) {_isNeedClearDisp1 = 1; _disp31oldLength = 0;} 
}
if (_dms1Q30) {
_dispTempLength1 = ((String("*"))).length();
if (_disp30oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp30oldLength = _dispTempLength1;
_lcd1.setCursor(13, 1);
_lcd1.print((String("*")));
} else {
if (_disp30oldLength > 0) {_isNeedClearDisp1 = 1; _disp30oldLength = 0;} 
}
if (_dms1Q29) {
_dispTempLength1 = ((String("*"))).length();
if (_disp29oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp29oldLength = _dispTempLength1;
_lcd1.setCursor(12, 1);
_lcd1.print((String("*")));
} else {
if (_disp29oldLength > 0) {_isNeedClearDisp1 = 1; _disp29oldLength = 0;} 
}
if (_dms1Q28) {
_dispTempLength1 = ((String("*"))).length();
if (_disp28oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp28oldLength = _dispTempLength1;
_lcd1.setCursor(11, 1);
_lcd1.print((String("*")));
} else {
if (_disp28oldLength > 0) {_isNeedClearDisp1 = 1; _disp28oldLength = 0;} 
}
if (_dms1Q27) {
_dispTempLength1 = ((String("*"))).length();
if (_disp27oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp27oldLength = _dispTempLength1;
_lcd1.setCursor(10, 1);
_lcd1.print((String("*")));
} else {
if (_disp27oldLength > 0) {_isNeedClearDisp1 = 1; _disp27oldLength = 0;} 
}
if (_dms1Q26) {
_dispTempLength1 = ((String("*"))).length();
if (_disp26oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp26oldLength = _dispTempLength1;
_lcd1.setCursor(9, 1);
_lcd1.print((String("*")));
} else {
if (_disp26oldLength > 0) {_isNeedClearDisp1 = 1; _disp26oldLength = 0;} 
}
if (_dms1Q25) {
_dispTempLength1 = ((String("*"))).length();
if (_disp25oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp25oldLength = _dispTempLength1;
_lcd1.setCursor(8, 1);
_lcd1.print((String("*")));
} else {
if (_disp25oldLength > 0) {_isNeedClearDisp1 = 1; _disp25oldLength = 0;} 
}
if (_dms1Q24) {
_dispTempLength1 = ((String("*"))).length();
if (_disp24oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp24oldLength = _dispTempLength1;
_lcd1.setCursor(7, 1);
_lcd1.print((String("*")));
} else {
if (_disp24oldLength > 0) {_isNeedClearDisp1 = 1; _disp24oldLength = 0;} 
}
if (_dms1Q23) {
_dispTempLength1 = ((String("*"))).length();
if (_disp23oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp23oldLength = _dispTempLength1;
_lcd1.setCursor(6, 1);
_lcd1.print((String("*")));
} else {
if (_disp23oldLength > 0) {_isNeedClearDisp1 = 1; _disp23oldLength = 0;} 
}
if (_dms1Q22) {
_dispTempLength1 = ((String("*"))).length();
if (_disp22oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp22oldLength = _dispTempLength1;
_lcd1.setCursor(5, 1);
_lcd1.print((String("*")));
} else {
if (_disp22oldLength > 0) {_isNeedClearDisp1 = 1; _disp22oldLength = 0;} 
}
if (_dms1Q21) {
_dispTempLength1 = ((String("*"))).length();
if (_disp21oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp21oldLength = _dispTempLength1;
_lcd1.setCursor(4, 1);
_lcd1.print((String("*")));
} else {
if (_disp21oldLength > 0) {_isNeedClearDisp1 = 1; _disp21oldLength = 0;} 
}
if (_dms1Q20) {
_dispTempLength1 = ((String("*"))).length();
if (_disp20oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp20oldLength = _dispTempLength1;
_lcd1.setCursor(3, 1);
_lcd1.print((String("*")));
} else {
if (_disp20oldLength > 0) {_isNeedClearDisp1 = 1; _disp20oldLength = 0;} 
}
if (_dms1Q19) {
_dispTempLength1 = ((String("*"))).length();
if (_disp19oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp19oldLength = _dispTempLength1;
_lcd1.setCursor(2, 1);
_lcd1.print((String("*")));
} else {
if (_disp19oldLength > 0) {_isNeedClearDisp1 = 1; _disp19oldLength = 0;} 
}
if (_dms1Q18) {
_dispTempLength1 = ((String("*"))).length();
if (_disp18oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp18oldLength = _dispTempLength1;
_lcd1.setCursor(1, 1);
_lcd1.print((String("*")));
} else {
if (_disp18oldLength > 0) {_isNeedClearDisp1 = 1; _disp18oldLength = 0;} 
}
if (_dms1Q17) {
_dispTempLength1 = ((String("*"))).length();
if (_disp17oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp17oldLength = _dispTempLength1;
_lcd1.setCursor(0, 1);
_lcd1.print((String("*")));
} else {
if (_disp17oldLength > 0) {_isNeedClearDisp1 = 1; _disp17oldLength = 0;} 
}
if (_dms1Q16) {
_dispTempLength1 = ((String("*"))).length();
if (_disp16oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp16oldLength = _dispTempLength1;
_lcd1.setCursor(15, 0);
_lcd1.print((String("*")));
} else {
if (_disp16oldLength > 0) {_isNeedClearDisp1 = 1; _disp16oldLength = 0;} 
}
if (_dms1Q15) {
_dispTempLength1 = ((String("*"))).length();
if (_disp15oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp15oldLength = _dispTempLength1;
_lcd1.setCursor(14, 0);
_lcd1.print((String("*")));
} else {
if (_disp15oldLength > 0) {_isNeedClearDisp1 = 1; _disp15oldLength = 0;} 
}
if (_dms1Q14) {
_dispTempLength1 = ((String("*"))).length();
if (_disp14oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp14oldLength = _dispTempLength1;
_lcd1.setCursor(13, 0);
_lcd1.print((String("*")));
} else {
if (_disp14oldLength > 0) {_isNeedClearDisp1 = 1; _disp14oldLength = 0;} 
}
if (_dms1Q13) {
_dispTempLength1 = ((String("*"))).length();
if (_disp13oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp13oldLength = _dispTempLength1;
_lcd1.setCursor(12, 0);
_lcd1.print((String("*")));
} else {
if (_disp13oldLength > 0) {_isNeedClearDisp1 = 1; _disp13oldLength = 0;} 
}
if (_dms1Q12) {
_dispTempLength1 = ((String("*"))).length();
if (_disp12oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp12oldLength = _dispTempLength1;
_lcd1.setCursor(11, 0);
_lcd1.print((String("*")));
} else {
if (_disp12oldLength > 0) {_isNeedClearDisp1 = 1; _disp12oldLength = 0;} 
}
if (_dms1Q11) {
_dispTempLength1 = ((String("*"))).length();
if (_disp11oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp11oldLength = _dispTempLength1;
_lcd1.setCursor(10, 0);
_lcd1.print((String("*")));
} else {
if (_disp11oldLength > 0) {_isNeedClearDisp1 = 1; _disp11oldLength = 0;} 
}
if (_dms1Q10) {
_dispTempLength1 = ((String("*"))).length();
if (_disp10oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp10oldLength = _dispTempLength1;
_lcd1.setCursor(9, 0);
_lcd1.print((String("*")));
} else {
if (_disp10oldLength > 0) {_isNeedClearDisp1 = 1; _disp10oldLength = 0;} 
}
if (_dms1Q9) {
_dispTempLength1 = ((String("*"))).length();
if (_disp9oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp9oldLength = _dispTempLength1;
_lcd1.setCursor(8, 0);
_lcd1.print((String("*")));
} else {
if (_disp9oldLength > 0) {_isNeedClearDisp1 = 1; _disp9oldLength = 0;} 
}
if (_dms1Q8) {
_dispTempLength1 = ((String("*"))).length();
if (_disp8oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp8oldLength = _dispTempLength1;
_lcd1.setCursor(7, 0);
_lcd1.print((String("*")));
} else {
if (_disp8oldLength > 0) {_isNeedClearDisp1 = 1; _disp8oldLength = 0;} 
}
if (_dms1Q7) {
_dispTempLength1 = ((String("*"))).length();
if (_disp7oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp7oldLength = _dispTempLength1;
_lcd1.setCursor(6, 0);
_lcd1.print((String("*")));
} else {
if (_disp7oldLength > 0) {_isNeedClearDisp1 = 1; _disp7oldLength = 0;} 
}
if (_dms1Q6) {
_dispTempLength1 = ((String("*"))).length();
if (_disp6oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp6oldLength = _dispTempLength1;
_lcd1.setCursor(5, 0);
_lcd1.print((String("*")));
} else {
if (_disp6oldLength > 0) {_isNeedClearDisp1 = 1; _disp6oldLength = 0;} 
}
if (_dms1Q5) {
_dispTempLength1 = ((String("*"))).length();
if (_disp5oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp5oldLength = _dispTempLength1;
_lcd1.setCursor(4, 0);
_lcd1.print((String("*")));
} else {
if (_disp5oldLength > 0) {_isNeedClearDisp1 = 1; _disp5oldLength = 0;} 
}
if (_dms1Q4) {
_dispTempLength1 = ((String("*"))).length();
if (_disp4oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp4oldLength = _dispTempLength1;
_lcd1.setCursor(3, 0);
_lcd1.print((String("*")));
} else {
if (_disp4oldLength > 0) {_isNeedClearDisp1 = 1; _disp4oldLength = 0;} 
}
if (_dms1Q3) {
_dispTempLength1 = ((String("*"))).length();
if (_disp3oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp3oldLength = _dispTempLength1;
_lcd1.setCursor(2, 0);
_lcd1.print((String("*")));
} else {
if (_disp3oldLength > 0) {_isNeedClearDisp1 = 1; _disp3oldLength = 0;} 
}
if (_dms1Q2) {
_dispTempLength1 = ((String("*"))).length();
if (_disp2oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp2oldLength = _dispTempLength1;
_lcd1.setCursor(1, 0);
_lcd1.print((String("*")));
} else {
if (_disp2oldLength > 0) {_isNeedClearDisp1 = 1; _disp2oldLength = 0;} 
}
if (_dms1Q1) {
_dispTempLength1 = ((String("*"))).length();
if (_disp1oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp1oldLength = _dispTempLength1;
_lcd1.setCursor(0, 0);
_lcd1.print((String("*")));
} else {
if (_disp1oldLength > 0) {_isNeedClearDisp1 = 1; _disp1oldLength = 0;} 
}
_gtv1 = _count1MaxLO;






}

bool _isTimer(unsigned long startTime, unsigned long period )
  {
  unsigned long currentTime;
currentTime = millis();
if (currentTime>= startTime) {return (currentTime>=(startTime + period));} else {return (currentTime >=(4294967295-startTime+period));}
  }
