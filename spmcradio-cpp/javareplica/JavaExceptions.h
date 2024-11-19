#pragma once
#include<exception>

#ifndef ArrayBlockingQueueExceptions_H
#define ArrayBlockingQueueExceptions_H

// from https://github.com/anandkulkarnisg/ArrayBlockingQueue
struct final IllegalArgumentException : std::exception {
	const char * what () const noexcept {
		return "Exception : -ve or zero size capacity arguments are not allowed. Please specify valid +ve capacity.";
	}
};

 struct final IllegalStateException : std::exception {
	const char * what () const noexcept {
		return "Exception: The queue is full. Hence the add method failed.";
	}
};

#endif