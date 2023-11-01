#pragma once

#define SAFE_DELEYE(aPointer)		\
	{								\
		if(nullptr != aPointer)		\
		{							\
			delete aPointer;		\
			aPointer = nullptr;		\
		}							\
	}


#define EQUL_RETURN_TRUE(aValue, bValue)	\
	{										\
		if(aValue == bValue)				\
		{									\
			return true;					\
		}									\
	}
#define EQUL_RETURN_FALSE(aValue, bValue)	\
	{										\
		if(aValue == bValue)				\
		{									\
			return false;					\
		}									\
	}
#define NOT_EQUL_RETURN_TRUE(aValue, bValue)	\
	{											\
		if(aValue != bValue)					\
		{										\
			return true;						\
		}										\
	}
#define NOT_EQUL_RETURN_FALSE(aValue, bValue)	\
	{											\
		if(aValue != bValue)					\
		{										\
			return false;						\
		}										\
	}


#define EQUL_BREAK(aValue, bValue)		\
{										\
	if(aValue == bValue)				\
	{									\
		break;							\
	}									\
}
#define NOT_EQUL_BREAK(aValue, bValue)	\
{										\
	if(aValue != bValue)				\
	{									\
		break;							\
	}									\
}

#define TRUE_BREAK(aValue) EQUL_BREAK(true, aValue)
#define FALSE_BREAK(aValue) EQUL_BREAK(false, aValue)
