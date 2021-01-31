// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>
struct C
{
  int data_member;
  void member_function() {};
};

struct Class
{
  int data{};

  void set(int n)
  {
    Class *pointer = this;
    this->data = n;
  }
};

struct Object
{
  int data_member;
  void member_function()
  {
    std::cout << data_member;
  }
};

int main()
{
  // Object test
  
  // Object::data_memberメンバーへのポインタ
  int Object::* int_ptr = &Object::data_member;
  // Object::member_functionメンバーへのポインタ
  void (Object::* func_ptr)() = &Object::member_function;

  // クラスのオブジェクト
  Object object;

  // objectに対するメンバーポインタを介した参照
  object.*int_ptr = 123;
  (object.*func_ptr)();

  // 別のオブジェクト
  Object another_object;
  another_object.data_member = 456;
  (another_object.*func_ptr)();


  // Class test
  Class a;
  Class b;

  a.set(1);
  b.set(2);

  // C test
  C object1;
  C *pointer = &object1;

  pointer->data_member = 0;
  pointer->member_function();
  (*(pointer)).data_member = 0;
  (*(pointer)).member_function();
}
