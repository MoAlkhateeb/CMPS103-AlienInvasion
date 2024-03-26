template <typename T>
class BagADT {
   public:
    virtual bool isEmpty() const = 0;

    virtual int getCount() const = 0;

    virtual bool add(const T& newEntry) = 0;

    virtual bool removeRandom(T& randomEntry) = 0;

    virtual void print() const = 0;

    virtual ~BagADT() {}
};