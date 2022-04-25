#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

template<class ExceptionType>
class PrecondViolatedExcep
{
public:
    PrecondViolatedExcep(const string& message = "")
    {
        m_msg = message;
    }

    string getMessage() const
    {
        return m_msg;
    }

    void setMessage(const string& message)
    {
        m_msg = message;
    }

    string toString() const
    {
        return m_msg;
    }
};
#endif