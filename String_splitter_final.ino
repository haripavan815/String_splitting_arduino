#include <StringSplitter.h>

#include "StringSplitter.h"
#include <ThingSpeak.h>
double data1,data2,data3,data4;

void setup() {
  Serial.begin(115200);
  Serial.println(F("StringSplitter Library Test"));

}
void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()) {
String strTest = Serial.readString();
  Serial.println("Test String: " + strTest);

  StringSplitter *splitter = new StringSplitter(strTest, ',', 6);  // new StringSplitter(string_to_split, delimiter, limit)
  int itemCount = splitter->getItemCount();
  Serial.println("Item count: " + String(itemCount));

  for(int i = 0; i < itemCount; i++){
    String item = splitter->getItemAtIndex(i); 
    item.toFloat();
    Serial.println("Item @ index " + String(i) + ": " + item);
    //strncpy(data, item.c_str(), 100);
    if (String(i) =="0") {data1 = item.toFloat();}
    if (String(i) =="1") {data2 = item.toFloat();}
    if (String(i) =="2") {data3 = item.toFloat();}
    if (String(i) =="3") {data4 = item.toFloat();}
    
  Serial.println("End of program.");
  //Serial.end();
}
    Serial.println(data1);
    Serial.println(data2);
    Serial.println(data3);
    Serial.println(data4);

}
}
