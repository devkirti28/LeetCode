class Spreadsheet {
    unordered_map<string,int> sheet;
    bool isCell(string s){
        return (s[0]>='A' && s[0]<='Z');
    }
public:
    Spreadsheet(int rows) {
        sheet.clear();
    }
    
    void setCell(string cell, int value) {
        sheet[cell]=value;        
    }
    
    void resetCell(string cell) {
        sheet.erase(cell);
    }
    
    int getValue(string formula) {
        
        int i=1;
        while(i<formula.size()){
            if(formula[i]=='+')break;
            i++;
        }
        string X =formula.substr(1,i-1);
        string Y =formula.substr(i+1);
        int xval = (isCell(X))? sheet[X] : stoi(X);
        int yval = (isCell(Y))? sheet[Y] : stoi(Y);
        return xval + yval;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */