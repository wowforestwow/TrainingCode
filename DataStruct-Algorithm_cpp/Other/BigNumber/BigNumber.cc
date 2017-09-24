#include <iostream>
#include <vector>

using namespace std;

#define max(x,y) ((x) > (y) ? (x) : (y))

class bigNumber{

public:
    bigNumber():sign(0),dotPos(0){}
    // 复制构造函数
    bigNumber(const bigNumber& b):sign(b.sign),dotPos(b.dotPos),num(b.num){}
    bigNumber(const unsigned& b):sign(b < 0 ? 1 : 0),dotPos(0){
        this->num.push_back(b);
        this->adjust();
    }

    // 输入输出
    friend istream& operator>>(istream& in,bigNumber& self);
    friend ostream& operator<<(ostream& out,bigNumber& self);

    // 调整进制 , 默认10进制
    bigNumber& adjust(const int& adj=10);

    // 清除前后的 0
    void removeZero();

    // 清零
    void clear();

    // 乘法操作
    bigNumber operator*(const bigNumber& b)const;
    bigNumber& operator*=(const bigNumber& b);
    // 乘法实现
    void mul(const bigNumber& b);

    // 加法实现
    bigNumber& operator+=(const bigNumber& b);

private:
    // 正负号 0 为正
    bool sign;
    // 小数点位置,从后往前数
    int dotPos;
    // 数字
    vector<int> num;
};

// 清零
void bigNumber::clear(){
    this->num.clear();
    this->sign ^= this->sign;
    this->dotPos ^= this->dotPos;
}

// 进制调整
bigNumber& bigNumber::adjust(const int& adj){

    // 没有数据则直接返回
    if (!this->num.size()){return *this;}

    // 首位先不做判断
    for (unsigned i(this->num.size() - 1);i!=0;--i){
        if (this->num[i] >= adj){
            this->num[i-1] += this->num[i] / adj;
            this->num[i] %= adj;
        }
    }

    // 首位的进位
    while (this->num.front() >= adj){
        this->num.insert(this->num.begin(),this->num.front() / adj);
        // 插入后进位那一位成了第二位
        this->num[1] = this->num[1] % adj;
    }

    return *this;
}

// 加法实现
bigNumber& bigNumber::operator+=(const bigNumber& b){
    // 加法必须两个符号相同,否则使用减法
    if (this->sign ^ b.sign) {cout<<"减法!"<<endl;return *this;}

    // 整数部分
    vector<int>::reverse_iterator aIter(this->num.rbegin() + this->dotPos);
    vector<int>::const_reverse_iterator bIter(b.num.rbegin() + b.dotPos);

    // 按位相加
    while (aIter != this->num.rend() && bIter != b.num.rend()){
        *aIter += *bIter;
        ++aIter;
        ++bIter;
    }

    // b 的更高位
    while (bIter != b.num.rend()){
        this->num.insert(this->num.begin(),*bIter);
        ++bIter;
    }

    // 小数部分
    unsigned aPos(this->num.size() - this->dotPos);
    unsigned bPos(b.num.size() - b.dotPos);

    while (aPos != this->num.size() && bPos != b.num.size()){
        this->num[aPos] += b.num[bPos];
        ++aPos;
        ++bPos;
    }

    // b 的更低位
    while (bPos != b.num.size()){
        this->num.push_back(b.num[bPos]);
        ++bPos;
    }

    // 小数点为最大的
    this->dotPos = max(this->dotPos,b.dotPos);

    // 进制调整
    this->adjust();

    return *this;
}

// 乘法实现
void bigNumber::mul(const bigNumber& b){
    // 保存原始的 this
    const bigNumber raw(*this);
    // this 清零
    this->clear();

    for (vector<int>::const_reverse_iterator i(b.num.rbegin());i!=b.num.rend();++i){
        // 用于乘法的临时量
        bigNumber t(raw);
        for (vector<int>::iterator j(t.num.begin());j!=t.num.end();++j){
            *j *= *i;
        }
        // 乘法的补位
        for (unsigned k(0);k != i - b.num.rbegin();++k){
            t.num.push_back(0);
        }
        *this += t;
    }

    // 小数点相加
    this->dotPos += b.dotPos;
}

// 乘法操作
bigNumber& bigNumber::operator*=(const bigNumber& b){

    this->mul(b);

    return *this;
}

bigNumber bigNumber::operator*(const bigNumber& b)const{
    bigNumber newBig(*this);

    return newBig *= b;
}

// 清除前后的 0
void bigNumber::removeZero(){

    while (this->num.size() > (unsigned)this->dotPos && !this->num.front()){
        this->num.erase(this->num.begin());
    }

    // 当小数点为0时不能从后面清除0,清除后面的 0 时要移动小数点
    while (this->num.size() && this->dotPos && !this->num.back()){
        this->num.pop_back();
        --this->dotPos;
    }
}

// 输入
istream& operator>>(istream& in,bigNumber& self){
    // 输入前清空
    self.clear();

    string str;
    in>>str;

    // 记录操作位置
    unsigned index(0);

    // 前面可能的正负号
    if (str.size()){
        switch (str[0]){
            case '-':
                self.sign = 1;
            case '+':
                ++index;
                break;
        }
    }

    while (index != str.size() && str[index] != '.'){
        self.num.push_back(str[index] - '0');
        ++index;
    }

    // 跳过 '.'
    ++index;

    while (index < str.size()){
        self.num.push_back(str[index] - '0');
        ++self.dotPos;
        ++index;
    }

    return in;
}

// 输出
ostream& operator<<(ostream& out,bigNumber& self){

    // 如果为空,输出 0
    if (self.num.empty()) {
        out<<0;
        return out;
    }

    // 去除前后的 0
    self.removeZero();

    // 真实的小数点位置
    int realDotPos(self.num.size() - self.dotPos);

    // 如果真实小数点小于0,要在队列前面加0,如果要输出 0.01 0.123 这样的 把 < 改为 <=
    while (realDotPos < 0){
        self.num.insert(self.num.begin(),0);
        ++realDotPos;
    }

    // 符号
    if (self.sign){cout<<'-';}

    // 输出
    for (unsigned i(0);i!=self.num.size();++i){
        if (i == (unsigned)realDotPos){out<<'.';}
        out<<self.num[i];
    }

    return out;
}

int main(){

    bigNumber raw;
    unsigned pow(0);

    while (cin>>raw>>pow){

        if (pow){
            bigNumber big(1);
            for (unsigned i(0);i!=pow;++i){
                big *= raw;
            }
            cout<<big<<endl;
        } else {
            cout<<0<<endl;
        }
    }

//  bigNumber a,b;
//  cin>>a>>b;
//  a*=b;
//  cout<<a<<endl;

    return 0;
}
