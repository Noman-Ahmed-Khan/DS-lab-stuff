#include <iostream>

using namespace std;

class Document{
    private:
        string* text;
    public:
        // default Consructor
        Document(){
            text=new string("NO DATA");
        };

        // Parametrized Contructor
        Document(string _text){
            this->text=new string(_text);
        };

        // Copy Contructor
        Document(Document &obj){
            this->text=new string(*obj.text);
        }

        Document &operator=(Document obj){

            delete text;
            this->text = new string (*obj.text);
            return *this;
        }



        // getter/setter
        void setText(string _text){
            delete text;
            text = new string(_text);
        }
        string setText(void){
            return *text;
        }

        //Display Function
        void displayText(void){
            cout<<endl<<"DATA:"<<endl;
            cout<<*text<<endl;
        }

        //destructor
        ~Document(){
            delete text;
        }
};

int main(){

    Document orignalObj("Life is a journey of growth, filled with challenges and joys. Its about finding purpose embracing change and nurturing relationships. ");

    Document copyObj1(orignalObj);
    Document copyObj2=orignalObj;
    

    cout<<endl<<endl<<"Before Changes";
    orignalObj.displayText();
    copyObj1.displayText();
    copyObj2.displayText();

    orignalObj.setText("DATA CHANGED");
    
    cout<<endl<<endl<<"After Changes";
    orignalObj.displayText();
    copyObj1.displayText();
    copyObj2.displayText();


    // as we can observe due to deep keep the change in orignal data dose not effect the copied vrsion
    return 0;
}