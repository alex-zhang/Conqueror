#ifndef __CONQUEROR_MACROS_H__
#define __CONQUEROR_MACROS_H__

// Generic macros
/// @name namespace conqueror
/// @{
#ifdef __cplusplus
  #define NS_CQRO_BEGIN  namespace conqueror {
  #define NS_CQRO_END    }
  #define USING_CQRO_ST  using namespace conqueror
  #define NS_CQRO        ::conqueror
#else
  #define NS_CQRO_BEGIN 
  #define NS_CQRO_END 
  #define USING_CQRO_ST 
  #define NS_CQRO
#endif
//  end of namespace group
/// @}

#endif  //__CONQUEROR_MACROS_H__