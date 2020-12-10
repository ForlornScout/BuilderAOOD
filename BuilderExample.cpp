#include <iostream>
using namespace std;

// Your end product 
class AppleProduct{
    string _product;
    string _input;
    string _processor;
    string _storage;
    string _price;

public:

    AppleProduct(string set_product) { _product = set_product; }

    void setProcessor(string set_processor) { _processor = set_processor; }

    void setInput(string set_input) { _input = set_input; }

    void setStorage(string set_storage) {_storage = set_storage;}

    void setPrice(string set_price){_price = set_price;}
    string getProcessor() { return _processor; }
    string getInput() { return _input; }
    
    void show() {
    	cout << "Apple Base Product Info: " <<_product << endl;
      cout << "Input Type: " <<_input << endl;
    	cout << "Processor Type: "<<_processor << endl << endl;
      cout << "Storage for base unit:" <<_storage << endl;
      cout << "Price per Unit:" <<_price << endl;
    }
};

// AppleProductBuilder Abstract Class all builders should have at least these methods
class AppleProductBuilder{
protected:
    AppleProduct *_apple_product;
public:
    virtual void getOtherParts() = 0;
    virtual void buildInput() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildStorage() = 0;
    virtual void price() = 0;
    AppleProduct* getAppleProduct(){ return _apple_product; }
};

// AppleProductBuilder concrete class knows only how to build iPhone AppleProduct!
class iPhoneBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPhone"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor");   }

    void buildInput() { _apple_product->setInput("Touchscreen Input");   }

    void buildStorage() { _apple_product->setInput("64GB");   }

    void price() { _apple_product->setInput("$1000");   }
};

// AppleProductBuilder concrete class knows only how to build Mac AppleProduct
class MacBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Mac"); }

    void buildProcessor() { _apple_product->setProcessor("Intel Core Processor"); }

    void buildInput() { _apple_product->setInput("Mouse and Keyboard Input");   }

    void buildStorage() { _apple_product->setInput("1 TB");   }

    void price() { _apple_product->setInput("$2500");   }
};

class appleWatchBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for appleWatch"); }

    void buildProcessor() { _apple_product->setProcessor("Intel Core Processor"); }

    void buildInput() { _apple_product->setInput("Touchscreen Input");   }

    void buildStorage() { _apple_product->setInput("20 GB");   }

    void price() { _apple_product->setInput("$500");   }
};

class macBookProBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for MacbookPro"); }

    void buildProcessor() { _apple_product->setProcessor("Intel Core Processor"); }

    void buildInput() { _apple_product->setInput("Touchpad Input");   }

    void buildStorage() { _apple_product->setInput("300 GB");   }

    void price() { _apple_product->setInput("$1500");   }
};


// Defines steps and tells to the builder that build in given order.
class Director{

    AppleProductBuilder *builder;

public:

    AppleProduct* createAppleProduct(AppleProductBuilder *builder) {
        builder->getOtherParts();
        builder->buildInput();
        builder->buildProcessor();
        builder->buildStorage();
        builder->price();
        return builder->getAppleProduct();
    }
};

int main() {
	
  Director dir;
  MacBuilder mb;
  iPhoneBuilder ib;
  appleWatchBuilder ab;
  macBookProBuilder pb;

	AppleProduct *mac = dir.createAppleProduct(&mb);
	AppleProduct *iphone = dir.createAppleProduct(&ib);
  AppleProduct *appleWatch = dir.createAppleProduct(&ab);
  AppleProduct *macBookPro = dir.createAppleProduct(&pb);
	
	mac->show();
  delete mac;

	iphone->show();
  delete iphone;  

  appleWatch->show();
  delete appleWatch;

  macBookPro->show();
  delete macBookPro;
    
	return 0;
}