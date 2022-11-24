#include <set>

std::set<int> operator+(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> new_set;
    for (auto s : s1)
    {
        new_set.insert(s);
    }
    for (auto s : s2)
    {
        new_set.insert(s);
    }
    return new_set;
}

std::set<int> operator-(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> new_set;
    for (auto s : s1)
    {
        new_set.insert(s);
    }
    for (auto s : s2)
    {
        new_set.erase(s);
    }
    return new_set;
}

std::set<int> operator^(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> new_set;
    for (auto s : s1)
    {
        new_set.insert(s);
    }
    for (auto s : s2)
    {
    	if (new_set.count(s) == 0)
            new_set.insert(s);
        else
            new_set.erase(s);
    }
    return new_set;
}

std::set<int> operator*(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> new_set;
    for (auto s : s1)
    {
        for (auto sd : s2)
        {
    	    new_set.insert(s+sd);
        }
    }
    
    return new_set;
}

std::set<std::string> operator*(const std::set<std::string>& s1,const std::set<std::string>& s2)
{
    std::set<std::string> new_set;
    for (auto s : s1)
    {
        for (auto sd : s2)
        {
    	    new_set.insert(s+sd);
        }
    }
    
    return new_set;
}

std::set<int> operator^(const std::set<int>& s1,const int n)
{
    std::set<int> new_set = s1;
    for(int i = 1; i < n; i++)
        new_set = new_set * s1;
    
    return new_set;
}

std::set<std::string> operator^(const std::set<std::string>& s1,const int n)
{
    if(n < 0)
        throw std::invalid_argument( "received negative value" );
    if(n == 0)
        return std::set<std::string>{""};
    std::set<std::string> new_set = s1;
    for(int i = 1; i < n; i++)
        new_set = new_set * s1;
    
    return new_set;
}
