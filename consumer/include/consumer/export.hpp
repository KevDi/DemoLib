
#ifndef CONSUMER_EXPORT_H
#define CONSUMER_EXPORT_H

#ifdef CONSUMER_STATIC
#  define CONSUMER_EXPORT
#  define CONSUMER_NO_EXPORT
#else
#  ifndef CONSUMER_EXPORT
#    ifdef Consumer_EXPORTS
        /* We are building this library */
#      define CONSUMER_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define CONSUMER_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef CONSUMER_NO_EXPORT
#    define CONSUMER_NO_EXPORT 
#  endif
#endif

#ifndef CONSUMER_DEPRECATED
#  define CONSUMER_DEPRECATED __declspec(deprecated)
#endif

#ifndef CONSUMER_DEPRECATED_EXPORT
#  define CONSUMER_DEPRECATED_EXPORT CONSUMER_EXPORT CONSUMER_DEPRECATED
#endif

#ifndef CONSUMER_DEPRECATED_NO_EXPORT
#  define CONSUMER_DEPRECATED_NO_EXPORT CONSUMER_NO_EXPORT CONSUMER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef CONSUMER_NO_DEPRECATED
#    define CONSUMER_NO_DEPRECATED
#  endif
#endif

#endif /* CONSUMER_EXPORT_H */
