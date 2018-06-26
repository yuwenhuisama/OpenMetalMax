#ifndef _H_IRISCOLOR_
#define _H_IRISCOLOR_

#include "DirectX/IrisCommon.h"
#include "Iris2D Util/IrisRefCounter.h"

namespace Iris2D
{	/**
	* \~english
	* Color class of Iris 2D
	*
	* A color is an object with R/G/B/A properties.
	*
	* Each property of a color is a byte valued [0, 255].
	*/
	/**
	* \~chinese
	* Iris 2D Color ��
	*
	* һ�� Color ��һ������ R/G/B/A ���ԵĶ���
	*
	* Color ÿ�����Զ���һ������ [0, 255] �� byte ��
	*/
	class IrisColor : public IrisRefCounter
	{
	private:
		DirectX::XMINT4 m_n4Color { 0, 0, 0, 0 };
		bool m_bModifyDirtyFlag = false;

	public:
		/**
		* \~english
		* Create a color object.
		* @param cRed Red property of created color.
		* @param cGreen Green property of created color.
		* @param cBlue Blue property of created color.
		* @param cAlpha Alpha property of created color.
		* @return If color has been created successfully pointer of IrisColor will be returned otherwise nullptr.
		*/
		/**
		* \~chinese
		* ����һ�� Color ����
		* @return ��� Color ���󴴽��ɹ���ô��������ָ����򷵻� nullptr��
		*/
		static IrisColor* Create(unsigned char cRed, unsigned char cGreen, unsigned char cBlue, unsigned char cAlpha);
		/**
		* \~english
		* Release a color.
		* @param pColor A pointer to color object to be released. After this function called, pointer taken will be set to nullptr.
		*/
		/**
		* \~chinese
		* �ͷ�һ�� Color ����
		* @param pColor ָ��Ҫ���ͷŵ� Color �����ָ�롣���ú���������֮�󣬴����ָ�뽫�ᱻ����Ϊ nullptr��
		*/
		static void Release(IrisColor*& pColor);

	public:

		/**
		* \~english
		* Set the red property of current color.
		* @param cRed Value of red property.
		*/
		/**
		* \~chinese
		* ���õ�ǰ����� Red ���ԡ�
		* @param cRed Red ���Ե�ֵ��
		*/
		void SetRed(unsigned char cRed);
		/**
		* \~english
		* Get the red property of current color.
		* @return The red property of current color.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Color �� Red ֵ��
		* @return ��ǰ Color �� Red ֵ��
		*/
		unsigned char GetRed() const;

		/**
		* \~english
		* Set the green property of current color.
		* @param cGreen Value of green property.
		*/
		/**
		* \~chinese
		* ���õ�ǰ����� Green ���ԡ�
		* @param cGreen Green ���Ե�ֵ��
		*/
		void SetGreen(unsigned char cGreen);
		/**
		* \~english
		* Get the green property of current color.
		* @return The green property of current color.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Color �� Green ֵ��
		* @return ��ǰ Color �� Green ֵ��
		*/
		unsigned char GetGreen() const;

		/**
		* \~english
		* Set the blue property of current color.
		* @param cBlue Value of blue property.
		*/
		/**
		* \~chinese
		* ���õ�ǰ����� Blue ���ԡ�
		* @param cBlue Blue ���Ե�ֵ��
		*/
		void SetBlue(unsigned char cBlue);
		/**
		* \~english
		* Get the blue property of current color.
		* @return The blue property of current color.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Color �� Blue ֵ��
		* @return ��ǰ Color �� Blue ֵ��
		*/
		unsigned char GetBlue() const;

		/**
		* \~english
		* Set the alpha property of current color.
		* @param cAlpha Value of alpha property.
		*/
		/**
		* \~chinese
		* ���õ�ǰ����� Alpha ���ԡ�
		* @param cAlpha Alpha ���Ե�ֵ��
		*/
		void SetAlpha(unsigned char cAlpha);
		/**
		* \~english
		* Get the alpha property of current color.
		* @return The alpha property of current color.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Color �� Alpha ֵ��
		* @return ��ǰ Color �� Alpha ֵ��
		*/
		unsigned char GetAlpha() const;

		/**
		* \~english
		* Set R/G/B/A properties of current color.
		* @param cRed Value of red property.
		* @param cGreen Value of green property.
		* @param cBlue Value of green property.
		* @param cAlpha Value of alpha property.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Color ��R/G/B/A ���ԡ�
		* @param cRed Red ���Ե�ֵ��
		* @param cGreen Green ���Ե�ֵ��
		* @param cBlue Blue ���Ե�ֵ��
		* @param cAlpha Alpha ���Ե�ֵ��
		*/
		void Set(unsigned char cRed, unsigned char cGreen, unsigned char cBlue, unsigned char cAlpha);

		bool Modified();
		void ModifyDone();

	private:
		IrisColor() = default;
		~IrisColor() = default;
	};

	typedef IrisColor IrisTone;
}
#endif // !_H_IRISCOLOR_
