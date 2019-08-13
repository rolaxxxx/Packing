#include "SearchFactory.h"
#include "search/SearchUnform.h"

SearchFactory::SearchFactory()
{

}
ASearch* SearchFactory::create(std::string type)
{
    if(type=="Uniform")
    {
        return new SearchUnform();
    }

    std::cerr<<"Klaida tokio modulio nera!!!\n";

    exit(1000);
}
