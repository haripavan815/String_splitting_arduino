#include "StringSplitter.h"
#include <ThingSpeak.h>


void setup() {
  Serial.begin(115200);
  Serial.println(F("StringSplitter Library Test"));


}
void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()) {
String strTest = Serial.readString();
  Serial.println("Test String: " + strTest);

  StringSplitter *splitter = new StringSplitter(strTest, ',' , 10);  // new StringSplitter(string_to_split, delimiter, limit)
  int itemCount = splitter->getItemCount();
  Serial.println("Item count: " + String(itemCount));

  for(int i = 0; i < itemCount; i++){
    String item = splitter->getItemAtIndex(i);
    item.toFloat();
    Serial.println("Item @ index " + String(i) + ": " + item);
    
  }

  Serial.println(F("End of program."));
  //Serial.end();
}

}
