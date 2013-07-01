from cython.operator cimport dereference as dref
from libc.stdlib cimport malloc, free
from cpppython.hash import hash_any

cdef extern from "linked_list.h":
    cdef cppclass LinkedList[T]:
        LinkedList()
        size_t add(T element)
        size_t length()
        T pop() except +
        void remove(size_t i) except +
        T get(size_t i) except +

        


cdef class PyLinkedList:
    cdef LinkedList[long int] *thisptr
    store = {}
    def __cinit__(self):
        self.thisptr = new LinkedList[long int]()
    def __dealloc__(self):
        del self.thisptr

    def add(self, element):
        cdef long int key = hash_any(element)
        self.store[<object> key] = element
        self.thisptr.add(key)

    def length(self):
        return <object> self.thisptr.length()

    def pop(self):
        cdef long int key = self.thisptr.pop()
        retval = self.store[<object> key]
        del self.store[<object> key]
        return retval

    def remove(self, i):
        self.thisptr.remove(<size_t> i)

    def get(self, i):
        cdef long int key = self.thisptr.get(i)
        return self.store[<object> key]

    def __len__(self):
        return <object> self.thisptr.length()

    def __getitem__(self, i):
        if i<0:
            return self.get(len(self) + i)
        return self.get(i)


