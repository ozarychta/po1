#include <cstring>
#include <iostream>

using namespace std;
template <typename T, typename Wzorzec>   
class Map
{  
private:   
  struct node
  {
    node *next;
    T key;
    Wzorzec val;
    node (T k):next (NULL)
    {
      key = k;
    };
    ~node ()
    {
  
    }
    node (const node & s):next (NULL)
    {
      key=s.key;
      val=s.val;
    };
      
  private:			
    node & operator= (const node &);
  };
  node *head;
 
  void clear ();
  void swap (Map & l);
  
  public:
  Map();
  Map(const Map & l);
  Map& operator=(const Map& l);
  ~Map();
  void Add(T key, Wzorzec value);
  Wzorzec* Find(T key) const;      
    
  template <typename Typ, typename Szablon>
  friend ostream & operator <<(ostream & s, const Map<Typ,Szablon> &a);
      
};

template <typename T, typename Wzorzec>
Map<T, Wzorzec>::Map ()
{
  head = NULL;
}

template <typename T, typename Wzorzec>
void Map<T, Wzorzec>::clear ()
{
  while (head)
    {
      node *t = head->next;
      delete head;
      head = t;
    };
}

template <typename T, typename Wzorzec>
Map<T, Wzorzec>::~Map ()
{
  clear ();
    
}

template <typename T, typename Wzorzec>
void Map<T, Wzorzec>::Add(T key, Wzorzec value)
{
  node *nowy = new node (key);
  nowy->next = head;
  head = nowy;
  head->val = value;
}

template <typename T, typename Wzorzec>
void Map<T, Wzorzec>::swap (Map<T,Wzorzec>& l)
{
  node *t = head;
  head = l.head;
  l.head = t;
}

template <typename T, typename Wzorzec>
Map<T,Wzorzec>::Map (const Map<T,Wzorzec>& l)
{
  node *src, **dst;
  head = NULL;
  src = l.head;
  dst = &head;
  try
  {
    while (src) 
      {
	*dst = new node (*src);
	src = src->next;
	dst = &((*dst)->next);  
      }
  }
  catch (...)
  {
    clear ();
    throw;
  };
}

template <typename T, typename Wzorzec>
Map<T,Wzorzec>& Map<T,Wzorzec>::operator= (const Map<T,Wzorzec> & l)
{
  if (&l == this)
    return *this;
  Map t (l);
  swap (t);
  return *this;
}

template <typename T, typename Wzorzec>
Wzorzec* Map<T,Wzorzec>::Find (T key) const 
{
  Wzorzec *wsk;
    node *c=head;
  while (c)
    {
      if (c->key==key)
      {
        wsk=&c->val;      
	    return wsk;
      }
      c = c->next;
    }
  return NULL;
}

template <typename T, typename Wzorzec>
ostream& operator<<(ostream & s, const Map<T,Wzorzec> &a)
{       
    typename Map<T,Wzorzec>::node *c=a.head;
    while (c)
    {
      s << "    " << c->key << "     " << c->val << endl;
      c = c->next;
    }
 
    return s;
}
