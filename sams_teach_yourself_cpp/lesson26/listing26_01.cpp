template <typename t>
class smart_pointer
{
private:
  t * raw_ptr;

public:
  smart_pointer (t * p_data) : raw_ptr(p_data) {}
  ~smart_pointer() {delete raw_ptr;};

  // copy constructor
  smart_pointer(const smart_pointer & another_sp);
  // copy assignment operator
  smart_pointer & operator = (const smart_pointer & another_sp);

  t & operator * () const // dereferencing operator
  {
    return *(raw_ptr);
  }

  t * operator -> () const // member selection operator
  {
    return raw_ptr;
  }
};
