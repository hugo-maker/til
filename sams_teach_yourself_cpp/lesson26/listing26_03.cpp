template <typename t>
class destructivecopy_ptr
{
private:
  t * object;
public:
  destructivecopy_ptr(t * input) : object(input) {}
  ~destructivecopy_ptr() {delete object;}

  // copy constructor
  destructivecopy_ptr(destructivecopy_ptr & source)
  {
    // Take ownership on copy
    object = source.object;

    // destroy source
    source.object = 0;
  }

  // copy assginment operator
  destructivecopy_ptr & operator = (destructivecopy_ptr & source)
  {
    if (object != source.object)
    {
      delete object;
      object = source.object;
      source.object = 0;
    }
  }
};

int main()
{
  destructivecopy_ptr<int> num(new int);
  destructivecopy_ptr<int> copy = num;

  // num is now invalid
  return 0;
}
