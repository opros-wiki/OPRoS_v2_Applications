
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0 [Symbol])
 *  
 */
#ifndef _PersonData_DATATYPE_H
#define _PersonData_DATATYPE_H
#include <archive/opros_access.h>
#include <device/ApiTypes.h>


#include <string>
            

/*
** 
** 
*/
class PersonData
{
protected:
	friend class opros::archive::access;
	int m_age;
	std::string m_name;
	
public:
	void save(opros::archive::oarchive &ar, const unsigned int) 
	{
		ar << m_age;
		ar << m_name;
		

	}

	void load(opros::archive::iarchive &ar, const unsigned int)
	{
		ar >> m_age;
		ar >> m_name;
		

	}
public:
	PersonData()
	{
	}

	PersonData(const int& in_age,const std::string& in_name)
	{
		m_age = in_age;
		m_name = in_name;
		
	}

	int& getAge()
	{
		return m_age;
	}

	void setAge(const int& in_age)
	{
		m_age = in_age;
	}

	std::string& getName()
	{
		return m_name;
	}

	void setName(const std::string& in_name)
	{
		m_name = in_name;
	}

	

};

inline std::string typeName(PersonData *p)
{
	return "PersonData";
}
#endif
