#include <iostream>

template <typename T>
class  StackElement
{
public:
    T m_key;
    StackElement<T>* m_nextElement;
    StackElement(T const& key, StackElement<T>* nextElement) :
        m_key(key),
        m_nextElement(nextElement)
    {};
};

template <typename T>
class CMyStack
{
public:
    CMyStack() 
    { 
        m_ptrTop = nullptr; 
    }

    //копирование
    CMyStack(const CMyStack& stack)
    {
        StackElement<T>* elementPtrTemp1;
        StackElement<T>* elementPtrTemp2;
        StackElement<T>* elementPtrTemp3 = nullptr;

        if (m_ptrTop != nullptr)
        {
            Clear();
        }

        elementPtrTemp1 = stack.m_ptrTop;
        while (elementPtrTemp1 != nullptr)
        {
            elementPtrTemp2 = new StackElement<T>(elementPtrTemp1->m_key, nullptr);

            if (elementPtrTemp2 == NULL)
            {
                throw "Can't copy stack";
                return;
            }


            if (m_ptrTop == nullptr)
            {
                m_ptrTop = elementPtrTemp2;
                elementPtrTemp3 = elementPtrTemp2;
            }
            else
            {
                elementPtrTemp3->m_nextElement = elementPtrTemp2;
                elementPtrTemp3 = elementPtrTemp3->m_nextElement;
            }

            elementPtrTemp1 = elementPtrTemp1->m_nextElement;
        }
    }
    
    //присваивание копированием
    CMyStack<T>& operator=(const CMyStack<T>& stack)
    {
        if (m_ptrTop != nullptr)
        {
            Clear();
        }

        StackElement<T>* elementPtrTemp1;
        StackElement<T>* elementPtrTemp2;
        StackElement<T>* elementPtrTemp3 = nullptr;

        elementPtrTemp1 = stack.m_ptrTop;
        while (elementPtrTemp1 != nullptr)
        {
            elementPtrTemp2 = new StackElement<T>(elementPtrTemp1->m_key, nullptr);

            if (elementPtrTemp2 == NULL)
            {
                throw "Can't copy stack";
                return *this;
            }

            if (m_ptrTop == nullptr)
            {
                m_ptrTop = elementPtrTemp2;
                elementPtrTemp3 = elementPtrTemp2;
            }
            else
            {
                elementPtrTemp3->m_nextElement = elementPtrTemp2;
                elementPtrTemp3 = elementPtrTemp3->m_nextElement;
            }

            elementPtrTemp1 = elementPtrTemp1->m_nextElement;
        }
        return *this;
    }

    //перемещение
    CMyStack(CMyStack&& stack) 
    {
        StackElement<T>* elementPtrTemp1;
        StackElement<T>* elementPtrTemp2;
        StackElement<T>* elementPtrTemp3 = nullptr;

        if (m_ptrTop != nullptr)
        {
            Clear();
        }

        elementPtrTemp1 = stack.m_ptrTop;
        while (elementPtrTemp1 != nullptr)
        {
            elementPtrTemp2 = new StackElement<T>(elementPtrTemp1->m_key, nullptr);

            if (elementPtrTemp2 == NULL)
            {
                throw "Can't copy stack";
                return;
            }


            if (m_ptrTop == nullptr)
            {
                m_ptrTop = elementPtrTemp2;
                elementPtrTemp3 = elementPtrTemp2;
            }
            else
            {
                elementPtrTemp3->m_nextElement = elementPtrTemp2;
                elementPtrTemp3 = elementPtrTemp3->m_nextElement;
            }

            elementPtrTemp1 = elementPtrTemp1->m_nextElement;
        };
        stack.Clear();
    }

    //присваивание перемещением
    CMyStack<T>& operator=(CMyStack<T>&& stack)
    {
        if (m_ptrTop != nullptr)
        {
            Clear();
        }

        StackElement<T>* elementPtrTemp1;
        StackElement<T>* elementPtrTemp2;
        StackElement<T>* elementPtrTemp3 = nullptr;

        elementPtrTemp1 = stack.m_ptrTop;
        while (elementPtrTemp1 != nullptr)
        {
            elementPtrTemp2 = new StackElement<T>(elementPtrTemp1->m_key, nullptr);

            if (elementPtrTemp2 == NULL)
            {
                throw "Can't copy stack";
                return *this;
            }

            if (m_ptrTop == nullptr)
            {
                m_ptrTop = elementPtrTemp2;
                elementPtrTemp3 = elementPtrTemp2;
            }
            else
            {
                elementPtrTemp3->m_nextElement = elementPtrTemp2;
                elementPtrTemp3 = elementPtrTemp3->m_nextElement;
            }

            elementPtrTemp1 = elementPtrTemp1->m_nextElement;
        }
        stack.Clear();
        return *this;
    }


    bool Push(T value)
    {
        StackElement<T>* element;
        element = new StackElement<T>(value, m_ptrTop);
        if (element == NULL)
        {
            throw "Can't push element";
            return false;
        }

        m_ptrTop = element;
        return true;
    }

    void Clear()
    {
        StackElement<T>* elementPtr;
        StackElement<T>* elementPtrTemp;

        elementPtr = m_ptrTop;

        while (elementPtr != nullptr)
        {
            elementPtrTemp = elementPtr;
            elementPtr = elementPtr->m_nextElement; 
            delete elementPtrTemp;
        }
        m_ptrTop = nullptr;
    }

    ~CMyStack()
    {
        Clear();
    }

    bool IsEmpty() const
    {
        if (m_ptrTop == nullptr)
        {
            return true;
        }
        return false;
    }

    bool Pop()
    {
        if (m_ptrTop == nullptr)
        {
            throw "Empty stack. Can't pop";
            return false;
        }
            
        StackElement<T>* elementPtrTemp;

        elementPtrTemp = m_ptrTop;
        m_ptrTop = m_ptrTop->m_nextElement;

        delete elementPtrTemp;

        return true;
    }

    T GetTopElement() const
    {
        if (m_ptrTop == nullptr)
        {
            throw "Empty stack";
            return T();
        }

        T value = m_ptrTop->m_key;
        return value;
    }

    private:
        StackElement<T>* m_ptrTop;

};