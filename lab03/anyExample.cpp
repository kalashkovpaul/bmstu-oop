# include <iostream>
# include <memory>

using namespace std;

class Any
{
	template <typename Type>
	friend Type any_Cast(const Any& he);
	template <typename Type>
	friend const Type* any_Cast(const Any* he);

private:
	class BaseValue;
	unique_ptr<BaseValue> object;

public:
	Any() = default;
	Any(const Any& other);
	Any(Any&& other) noexcept;
	template <typename Type>
	Any(const Type& val);

	Any& operator =(const Any& other);
	Any& operator =(Any&& other) noexcept;
	template <typename Type>
	Any& operator =(const Type& val);
	template <typename Type>
	Any& emplace(const Type& val);

	bool has_value() const noexcept { return static_cast<bool>(object); }
	const std::type_info& type() const noexcept
	{
		return object ? object->type() : typeid(void);
	}
	void reset() { object.reset(); }

	template <typename Type>
	operator Type() const;

private:
	class BaseValue
	{
	public:
		virtual ~BaseValue() = default;
		virtual const std::type_info& type() const noexcept = 0;
		virtual unique_ptr<BaseValue> clone() const = 0;
	};

	template <typename Type>
	class Value : public BaseValue
	{
	private:
		Type object;

	public:
		Value(const Type& t) : object(t) {}

		virtual const std::type_info& type() const noexcept override
		{
			return typeid(object);
		}
		virtual unique_ptr<BaseValue> clone() const override
		{
			return make_unique<Value<Type>>(object);
		}

		Type get() const { return object; }
		const Type* getPtr() const { return &object; }
	};
};

template <typename Type>
Type any_Cast(const Any& he)
{
	if (typeid(Type) != he.type())
	{
		throw std::runtime_error("Bad any_cast!");
	}
	return Type(he);
}

template <typename Type>
const Type* any_Cast(const Any* he)
{
	Any::Value<Type>* type = dynamic_cast<Any::Value<Type>*>(he->object.get());

	return type ? type->getPtr() : nullptr;
}

# pragma region Any methods
Any::Any(const Any& other)
{
	if (other.object)
	{
		this->object = other.object->clone();
	}
}

Any::Any(Any&& other) noexcept
{
	this->object = move(other.object);
}

template <typename Type>
Any::Any(const Type& val)
{
	this->object = make_unique<Value<Type>>(val);
}

Any& Any::operator =(const Any& other)
{
	if (other.object)
	{
		this->object = other.object->clone();
	}
	else
	{
		this->object.reset();
	}

	return *this;
}

Any& Any::operator =(Any&& other) noexcept
{
	this->object = move(other.object);

	return *this;
}

template <typename Type>
Any& Any::operator =(const Type& val)
{
	return emplace(val);
}

template <typename Type>
Any& Any::emplace(const Type& val)
{
	this->object = make_unique<Value<Type>>(val);

	return *this;
}

template <typename Type>
Any::operator Type() const
{
	Value<Type>& type = dynamic_cast<Value<Type>&>(*object);

	return type.get();
}
#pragma endregion

Any f()
{
	Any temp = 7.5;

	return temp;
}

int main()
{
	try
	{
		Any v1 = 2, v2 = v1, v3 = f(), v4;

		if (v3.has_value())
		{
			cout << v3.type().name() << endl;

			if (v3.type() == typeid(double))
				cout << "v3 = " << double(v3) << endl;
		}

		v4 = f();

		v1.reset();
		int j = 7;
		int& aj = j;
		v1 = j;
		cout << "v1 = " << any_Cast<int>(v1) << endl;

		cout << "v2 = " << any_Cast<int>(v2) << endl;
		v2.emplace(5.0f);
		cout << "v2 = " << any_Cast<float>(v2) << endl;

		int i = v1;
		float d = v2;
		cout << "i = " << i << " f = " << d << endl;
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
    return 0;
}