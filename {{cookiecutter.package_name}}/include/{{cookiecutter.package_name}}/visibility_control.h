#ifndef {{cookiecutter.__package_name_upper}}__VISIBILITY_CONTROL_H_
#define {{cookiecutter.__package_name_upper}}__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define {{cookiecutter.__package_name_upper}}_EXPORT __attribute__ ((dllexport))
    #define {{cookiecutter.__package_name_upper}}_IMPORT __attribute__ ((dllimport))
  #else
    #define {{cookiecutter.__package_name_upper}}_EXPORT __declspec(dllexport)
    #define {{cookiecutter.__package_name_upper}}_IMPORT __declspec(dllimport)
  #endif
  #ifdef {{cookiecutter.__package_name_upper}}_BUILDING_LIBRARY
    #define {{cookiecutter.__package_name_upper}}_PUBLIC {{cookiecutter.__package_name_upper}}_EXPORT
  #else
    #define {{cookiecutter.__package_name_upper}}_PUBLIC {{cookiecutter.__package_name_upper}}_IMPORT
  #endif
  #define {{cookiecutter.__package_name_upper}}_PUBLIC_TYPE {{cookiecutter.__package_name_upper}}_PUBLIC
  #define {{cookiecutter.__package_name_upper}}_LOCAL
#else
  #define {{cookiecutter.__package_name_upper}}_EXPORT __attribute__ ((visibility("default")))
  #define {{cookiecutter.__package_name_upper}}_IMPORT
  #if __GNUC__ >= 4
    #define {{cookiecutter.__package_name_upper}}_PUBLIC __attribute__ ((visibility("default")))
    #define {{cookiecutter.__package_name_upper}}_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define {{cookiecutter.__package_name_upper}}_PUBLIC
    #define {{cookiecutter.__package_name_upper}}_LOCAL
  #endif
  #define {{cookiecutter.__package_name_upper}}_PUBLIC_TYPE
#endif

#endif  // {{cookiecutter.__package_name_upper}}__VISIBILITY_CONTROL_H_
