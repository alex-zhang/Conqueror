#ifndef __SMARTCODE_MACROS_H__
#define __SMARTCODE_MACROS_H__

// Generic macros
/// @name namespace smartcode
/// @{
#ifdef __cplusplus
  #define NS_ST_BEGIN   namespace smartcode {
  #define NS_ST_END     }
  #define USING_NS_ST   using namespace smartcode
  #define NS_ST         ::smartcode
#else
  #define NS_ST_BEGIN 
  #define NS_ST_END 
  #define USING_NS_ST 
  #define NS_ST
#endif
//  end of namespace group
/// @}

#endif  //__SMARTCODE_MACROS_H__