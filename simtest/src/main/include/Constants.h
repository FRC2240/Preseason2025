namespace CONSTANTS
{

  // An additive threshold (+/- value) that checks if 2 values (target & source)
  // are within a range A template so it can be used with units. Call it by:
  // CONSTANTS::IN_THRESHOLD<type>(x,y,z)
  template <typename T>
  static bool IN_THRESHOLD(T source, T target, T range)
  {
    return (source >= target - range && source <= target + range);
  }
}