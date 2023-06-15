#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#ifdef LIBRARY_EXPORT
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif // LIBRARY_EXPORT

void LIBRARY_API HelloLibrary();

#endif // !__LIBRARY_H__
