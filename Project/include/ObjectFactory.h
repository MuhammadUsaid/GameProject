#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H


class ObjectFactory
{
    public:
        ObjectFactory()
        {
            object = NULL;
        };
        virtual ~ObjectFactory();
        GameObject* getObject(int type)
        {
            if (type == 0)
            {
                object = new Enemy();
            }
            else if (type == 1)
            {
                object = new Weapon();
            }
            else if (type == 2)
            {
                object = new Bed();
            }
            else if (type == 3)
            {
                object = new Chair();
            }
            else if (type == 4)
            {
                object = new Key();
            }
            else if (type == 5)
            {
                object = new LabCoat();
            }
            else if (type == 6)
            {
                object = new Cupboard();
            }
            return object;
        }

    protected:

    private:
};

#endif // OBJECTFACTORY_H
