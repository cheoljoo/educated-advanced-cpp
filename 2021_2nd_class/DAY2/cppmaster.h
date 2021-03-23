// MODULE  : cppmaster.h
// COMMENT : 
// EMAIL   : smkang @ codenuri.co.kr
// HOME    : www.ecourse.co.kr
// VERSION : 2.0
// DATE    : 2020.09

#ifndef CPPMASTER_H
#define CPPMASTER_H

#if _MSC_VER > 1000
#pragma  once
#endif

#ifdef UNICODE
#undef _UNICODE
#undef UNICODE
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <type_traits>

// + + + + + + + + + + + + + + + + + + + + +
// useful macro
//
#define CONVERT_VARIABLE_TO_STRING(Variable) (#Variable)

#define EXPAND( x ) x
#define GET_COUNT_VA_ARGS(...) EXPAND(GET_COUNT_VA_ARGS_IMPL(__VA_ARGS__, 5,4,3,2,1))
#define GET_COUNT_VA_ARGS_IMPL(_1,_2,_3,_4,_5,N,...) N

#define MACRO_DISPATCHER(func, ...)       MACRO_DISPATCHER_(func, GET_COUNT_VA_ARGS(__VA_ARGS__))
#define MACRO_DISPATCHER_(func, nargs)    MACRO_DISPATCHER__(func, nargs)
#define MACRO_DISPATCHER__(func, nargs)   func ## nargs

// + + + + + + + + + + + + + + + + + + + + +
// show()
#define show(...) MACRO_DISPATCHER(show, __VA_ARGS__)(__VA_ARGS__)
#define show1(container)   __show_container(#container, container)
#define show2(first, last) __show_iterator(#first, #last, first, last)

template<typename T> void __show_range(T first, T last)
{
	if (first == last) return;
	std::cout << *first;
	while (++first != last)
		std::cout << ", " << *first;
}
template<typename T> void __show_container(std::string name, T&& cont)
{
	std::cout << name << " : [ ";
	__show_range(std::begin(cont), std::end(cont));
	std::cout << " ]" << std::endl;
}
template<typename T> void __show_iterator(std::string sfirst, std::string slast, T first, T last)
{
	std::cout << sfirst << " ~ " << slast << " : [ ";
	__show_range(first, last);
	std::cout << " ]" << std::endl;
}

// + + + + + + + + + + + + + + + + + + + + +
// Log & debbug
struct Log
{
	void print(std::string msg, std::string sep = "\n") const
	{
		std::cout << msg << sep;
	}
};
Log debug;


// + + + + + + + + + + + + + + + + + + + + +
// LOG_TYPE_NAME() macro
//
// HOW TO BUILD
//	g++ main.cpp -IC:\boost_install_path\boost_1_70_0
//  cl  main.cpp -IC:\boost_install_path\boost_1_70_0 /EHsc

#ifdef __has_include
#	if __has_include(<boost/type_index.hpp>)    
#		include <boost/type_index.hpp>
#		define LOG_TYPE_NAME(...)  debug.print(boost::typeindex::type_id_with_cvr<__VA_ARGS__>().pretty_name())
#   endif
#endif

#ifndef LOG_TYPE_NAME
#   include <typeinfo>
#	define LOG_TYPE_NAME(...)	debug.print( typeid(__VA_ARGS__).name() )
#endif

// + + + + + + + + + + + + + + + + + + + + +
// LOG_FUNCTION_NAME() macro
//
#if defined(__GNUC__)
#	define _FNAME_ __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
#	define _FNAME_ __FUNCSIG__
#else
#	define _FNAME_ __FUNCTION__
#endif

// remove calling convention from "function name"
// change "foo(void)" => "foo()" 
std::string remove_calling_convention(std::string name)
{
	std::istringstream iss(name);
	std::ostringstream oss;
	std::string s;

	while (iss >> s)
	{
		// "foo(void)" => "foo()" in cl compiler
		if (s.size() > 6 && s.substr(s.size() - 6, 6) == "(void)") // foo(void)
		{
			s.replace(s.size() - 6, 6, "()");
			s.shrink_to_fit();
		}
		if (s != "__cdecl" && s != "__stdcall" && s != "__fastcall" && s != "__thiscall" && s != "thiscall")
			oss << s << " ";
	}
	return oss.str();
}
#define LOG_FUNCTION_NAME() debug.print( remove_calling_convention(_FNAME_) )


// + + + + + + + + + + + + + + + + + + + + +
// LOG_VALUE_CATEGORY() macro
//

#define LOG_VALUE_CATEGORY(...)												\
	if(std::is_lvalue_reference_v<decltype((__VA_ARGS__))>)					\
		debug.print(  #__VA_ARGS__ " : lvalue" );							\
	else if (std::is_rvalue_reference_v<decltype((__VA_ARGS__))>)			\
		debug.print(  #__VA_ARGS__ " : rvalue(xvalue)" );					\
	else																	\
		debug.print(  #__VA_ARGS__ " : rvalue(prvalue)" );



#endif	// CPPMASTER_H
