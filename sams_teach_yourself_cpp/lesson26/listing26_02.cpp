template <typename t>
class deepcopy_smart_ptr
{
private:
  t * object;
public:
  // ... other functions

  // copy constructor of the deepcopy pointer
  deepcopy_smart_ptr(const deepcopy_smart_ptr & source)
  {
    // clone() is virtual: ensure deep copy of Derived class object
    object = source->clone();
  }

  // copy assignment operator
  deepcopy_smart_ptr & operator = (const deepcopy_smart_ptr & source)
  {
    if (object)
    {
      delete object;
    }
    object = source->clone();
  }
};
