#ifndef _H_IRISSPRITE_

#include "DirectX/IrisCommon.h"
//#include "IrisTone.h"
#if IR_API_VERSION == 0
#else
#include "Iris2D Util/IrisSpriteShaderBuffers.h"
#endif

namespace Iris2D
{
	class IrisBitmap;
	class IrisRect;
	class IrisColor;
	class IrisViewport;
	typedef IrisColor IrisTone;
#ifdef _MSC_VER
	__declspec(align(16))
#endif
	/**
	* \~english 
	* Sprite class of Iris 2D
	*
	* A sprite abustractly represents something displayed on screen, further more, a sprite usually needs a bitmap to get an image to display or sprite won't show anything.
	*
	* A sprite can control the position, the scaling size, the angle and other displaying properties for an image, and it's the most basic element of 2D games.
	*/
	/** 
	* \~chinese
	* Iris 2D Sprite ��
	*
	* һ�� Sprite ����ر�ʾ����ʾ����Ļ�ϵ��κζ�������һ���أ�һ�� Sprite һ�㶼��Ҫһ�� Bitmap ����ʾͼƬ�ȣ����򽫲���չʾ�κζ�����
	*
	* һ��������Կ�����ʾ���ݵ�λ�á����ųߴ硢�Ƕ��Լ�������ʾ���ԣ����� 2D ��Ϸ�������Ԫ�ء�
	*/
	class IrisSprite
	{
	private:

		const float c_fPI = 3.14159f;
		const float c_fArcUnit = c_fPI / 180.0f;

		IrisBitmap* m_pBitmap = nullptr;
		IrisRect* m_pSrcRect = nullptr;
		IrisTone* m_pTone = nullptr;

		ID3D11Buffer* m_pVertexBuffer = nullptr;

		IrisSpriteVertexShaderBuffer m_bfVertexShaderBuffer;
		IrisSpritePixelShaderBuffer  m_bfPixelShaderBuffer;

		float m_fX = 0.0f;
		float m_fY = 0.0f;
		float m_fZ = 1.0f;
		float m_fAngle = 0.0f;
		float m_fZoomX = 1.0f;
		float m_fZoomY = 1.0f;
		
		bool m_bVisible = true;
		IrisViewport* m_pViewport = nullptr;

		bool m_bPositionDirtyFlag = false;
		bool m_bAngleDirtyFlag = false;
		bool m_bZoomDirtyFlag = false;
		bool m_bSrcRectDirtyFlag = false;
		bool m_bToneDirtyFlag = false;

	public:
		/**
		* \~english
		* Create a sprite object.
		*
		* @param pViewport The viewport in which current sprite is put. If nullptr is taken, current sprite will be put into global viewport.
		* @return If sprite has been created successfully pointer of IrisSprite will be returned otherwise nullptr.
		*/
		/**
		* \~chinese
		* ����һ�� Sprite ����
		*
		* @param pViewport �� Sprite ������ Viewport���������Ϊ nullptr ��ô��ǰ Sprite ���ᱻ����ȫ�� Viewport ֮�С�
		* @return ��� Sprite ���󴴽��ɹ���ô��������ָ����򷵻� nullptr��
		*/
		static IrisSprite* Create(IrisViewport* pViewport = nullptr);

		/**
		* \~english
		* Release a sprite.
		* @param pSprite A pointer to sprite object to be released. After this function called, pointer taken will be set to nullptr.
		*/
		/**
		* \~chinese
		* �ͷ�һ�� Sprite ����
		* @param pSprite ָ��Ҫ���ͷŵ� Sprite �����ָ�롣���ú���������֮�󣬴����ָ�뽫�ᱻ����Ϊ nullptr��
		*/
		static void Release(IrisSprite*& pSprite);

		static void InnerRelease(IrisSprite* pSprite);

	public:

		/**
		* \~english
		* Set bitmap object to current sprite, which is the image content of current sprite's display.
		*
		* If a bitmap has existed in current sprite, user should manually release it as Iris 2D won't automatically release it. This feature comes from thought about shared bitmap.
		* @param pBitmap A IrisBitmap object's pointer.
		*/
		/**
		* \~chinese
		* Ϊ��ǰ Sprite ���� Bitmap ���󣬸� Bitmap �����ǵ�ǰ Sprite ����ʾ���ݡ�
		*
		* ��������� Bitmap ֮ǰ�� Sprite �Ѿ����� Bitmap ����ô�û�Ӧ���ֶ��ͷ�֮ǰ�� Bitmap ��Iris 2D �����Զ��ͷ�֮ǰ�� Bitmap ���������Գ��ڶ��ڹ��� Bitmap �Ŀ��ǡ�
		* @param pBitmap һ�� IrisBitmap �����ָ�롣
		*/
		void SetBitmap(IrisBitmap*& pBitmap);
		IrisBitmap* GetBitmap() const;

		/**
		* \~english
		* Set the pixel x position of current sprite. (Under the GDI coordinate system).
		* @param fX The pixel x position of current sprite.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite ������ X ���ꡣ������ GDI ����ϵ��
		* @param fX ��ǰ Sprite ������ X ���ꡣ
		*/
		void SetX(float fX);
		/**
		* \~english
		* Get the pixel x position of current sprite. (Under the GDI coordinate system)
		* @ return the pixel x position of current sprite.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite ������ X ���ꡣ������ GDI ����ϵ��
		* @return ��ǰ Sprite ������ X ���ꡣ
		*/
		float GetX() const;

		/**
		* \~english
		* Set the pixel y position of current sprite. (Under the GDI coordinate system).
		* @param fY The pixel y position of current sprite.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite ������ Y ���ꡣ������ GDI ����ϵ��
		* @param fY ��ǰ Sprite ������ Y ���ꡣ
		*/
		void SetY(float fY);
		/**
		* \~english
		* Get the pixel y position of current sprite. (Under the GDI coordinate system)
		* @ return the pixel y position of current sprite.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite ������ Y ���ꡣ������ GDI ����ϵ��
		* @return ��ǰ Sprite ������ Y ���ꡣ
		*/
		float GetY() const;

		/**
		* \~english
		* Set the Z depth of current sprite. The depth of sprite decides the rending order of current sprite, the bigger Z is and the later sprite will be renderd.
		*
		* Range of Z is [0.0f, 9999.0f]
		* @param fZ depth of current sprite.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite �� Z ��ȡ� Sprite ����Ⱦ�����������Ⱦ���� Z Խ����ȾԽ����
		*
		* Z �ķ�ΧΪ [0.0f, 9999.0f]
		* @param fZ ��ǰ Sprite �� Z ��ȡ�
		*/
		void SetZ(float fZ);
		/**
		* \~english
		* Get the Z depth of current sprite.
		* @return Z depth of current sprite.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite �� Z ��ȡ�
		* @return ��ǰ Sprite �� Z ��ȡ�
		*/
		float GetZ() const;

		/**
		* \~english
		* Set the angle of current sprite. ( Angle Degree )
		* @param fAngle The angle of current sprite
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite �ĽǶȡ����Ƕ��ƣ�
		* @param fAngle ��ǰ Sprite �ĽǶȡ�
		*/
		void SetAngle(float fAngle);
		/**
		* \~english
		* Get the angle of current sprite. ( Angle Degree )
		* @return The angle of current sprite
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite �ĽǶȡ����Ƕ��ƣ�
		* @return ��ǰ Sprite �ĽǶȡ�
		*/
		float GetAngle() const;

		/**
		* \~english
		* Set the horizental scalling rate of current sprite.
		* @param fZoomX The horizental scalling rate of current sprite
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite �ĺ��������ʡ�
		* @param fZoomX ��ǰ Sprite �ĺ��������ʡ�
		*/
		void SetZoomX(float fZoomX);
		/**
		* \~english
		* Get the horizental scalling rate of current sprite.
		* @return The horizental scalling rate of current sprite
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite �ĺ��������ʡ�
		* @return ��ǰ Sprite �ĺ��������ʡ�
		*/
		float GetZoomX() const;

		/**
		* \~english
		* Set the vertical scalling rate of current sprite.
		* @param fZoomY The vertical scalling rate of current sprite
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite �����������ʡ�
		* @param fZoomY ��ǰ Sprite �����������ʡ�
		*/
		void SetZoomY(float fZoomY);
		/**
		* \~english
		* Get the vertical scalling rate of current sprite.
		* @return The vertical scalling rate of current sprite
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite �����������ʡ�
		* @return ��ǰ Sprite �����������ʡ�
		*/
		float GetZoomY() const;

		/**
		* \~english
		* Set origin transfer position of current sprite. 
		*
		* Initially, a sprite generated into screen is put at (-OX, -OY) where OX = 0 and OY = 0 defaultly and then moved to (-0X + X, OY + Y). (-OX, OY) is called origin transfer position.
		*
		* This property can be useful for rotating with any centern position.
		* @param fOX X position of origin transfer position of current sprite.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite �Ĵ���ԭ�㡣
		*
		* һ�������ɵ� Sprite һ��ʼ�ᱻ�ŵ���Ļ�� (-OX, -OY) ��λ�ã�Ĭ������� OX = 0 ���� OY = 0 ����Ȼ�����Żᱻ�ƶ��� ( -OX + X, -OY + Y �� ��( OX, OY ) ����Ϊ����ԭ�㡣
		*
		* ����������������Ϊ��ת���Ľ�����ת��ʱ���൱���á�
		* @param fOX ��ǰ Sprite ����ԭ��� X ���ꡣ
		*/
		void SetOX(float fOX);
		/**
		* \~english
		* Get X position of origin transfer position of current sprite.
		* @return X position of origin transfer position of current sprite.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite �Ĵ���ԭ��� X ���ꡣ
		* @return ��ǰ Sprite �Ĵ���ԭ��� X ���ꡣ
		*/
		float GetOX();

		/**
		* \~english
		* Set origin transfer position of current sprite.
		*
		* Initially, a sprite generated into screen is put at (-OX, -OY) where OX = 0 and OY = 0 defaultly and then moved to (-0X + X, -OY + Y). (OX, OY) is called origin transfer position.
		*
		* This property can be useful for rotating with any centern position.
		* @param fOY Y position of origin transfer position of current sprite.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite �Ĵ���ԭ�㡣
		*
		* һ�������ɵ� Sprite һ��ʼ�ᱻ�ŵ���Ļ�� (-OX, -OY) ��λ�ã�Ĭ������� OX = 0 ���� OY = 0 ����Ȼ�����Żᱻ�ƶ��� ( -OX + X, -OY + Y �� ��( OX, OY ) ����Ϊ����ԭ�㡣
		*
		* ����������������Ϊ��ת���Ľ�����ת��ʱ���൱���á�
		* @param fOY ��ǰ Sprite ����ԭ��� Y ���ꡣ
		*/
		void SetOY(float fOY);
		/**
		* \~english
		* Get Y position of origin transfer position of current sprite.
		* @return Y position of origin transfer position of current sprite.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite �Ĵ���ԭ��� Y ���ꡣ
		* @return ��ǰ Sprite �Ĵ���ԭ��� Y ���ꡣ
		*/
		float GetOY();

		/**
		* \~english
		* Set if current sprite displays mirrorly.
		* @param bMirror If true is sent, current sprite will display mirrorly otherwise normally.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite �Ƿ��Ծ�����ʾ��
		* @param bMirror �������Ϊ true ����ô�����Ծ�����ʾ������������ʾ��
		*/
		void SetMirror(bool bMirror);
		/**
		* \~english
		* Get if current sprite displays mirrorly.
		* @return If sprite displays mirrorly true will be returned otherwise false.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite �Ƿ��Ծ�����ʾ��
		* @return ����Ǿ�����ʾ���� true �����򷵻� false ��
		*/
		bool GetMirror();

		/**
		* \~english
		* Set if current sprite is visible.
		* @param bVisible If true is sent, current sprite will be visible otherwise invisible.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite �Ƿ�ɼ���
		* @param bVisible ������� true ����ô��ǰ Sprite �ɼ����򲻿ɼ���
		*/
		void SetVisible(bool bVisible);
		/**
		* \~english
		* Get if current sprite is visible.
		* @return If current sprite is visible true will be returned otherwise false.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite �Ƿ�ɼ���
		* @return �����ǰ Sprite �ɼ���ô���� true �����򷵻� false ��
		*/
		bool GetVisible();

		/**
		* \~english
		* Set opacity value of current sprite. The smaller this value is, the more transparent display of sprite will be.
		*
		* Opacity value's range is [0.0f, 255.0f]. If value taken is out of range, Iris 2D will autumatically modify it.
		*
		* @return Opacity value of current sprite.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite ��͸��ֵ�����ֵԽС�� Sprite Խ�ӽ�͸����
		*
		* ͸��ֵ�ķ�ΧΪ [0.0f, 255.0f]����������ֵ���ڸ÷�Χ�ڣ���ô Iris 2D �����Զ�����������
		*
		* @return ��ǰ Sprite ��͸��ֵ��
		*/
		void SetOpacity(float fOpacity);
		/**
		* \~english
		* Get opacity value of current sprite.
		* @return Opacity value of current sprite.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite ��͸��ֵ��
		* @return ��ǰ Sprite ��͸��ֵ��
		*/
		float GetOpacity();

		/**
		* \~english
		* Set a rect to limit the display content of bitmap of current sprite.
		* 
		* (0, 0) of current sprite's bitmap is origin position of taken rect. This function can be helpful to let sprite just show a part of current sprite's bitmap.
		* @param pSrcRect A pointer to the limit rect object.
		*/
		/**
		* \~chinese
		* ����һ�� Rect �����Ƶ�ǰ Sprite �� Bitmap ��ʾ�����ݡ�
		*
		* ��ǰ Sprite �� Bitmap �� (0, 0)  ���Ǵ���� Rect ��ԭ�㡣������������� Sprite ֻ��ʾ���� Bitmap ��һ���֡�
		* @param pSrcRect ָ������ Rect �����ָ�롣
		*/
		void SetSrcRect(IrisRect*& pSrcRect);
		/**
		* \~english
		* Get the limit rect of current sprite.
		* @return The pointer to the limit rect object.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite ������ Rect ��ָ�롣
		* @return ��ǰ Sprite ������ Rect ��ָ�롣
		*/
		IrisRect* GetSrcRect() const;

		/**
		* \~english
		* Set a tone object to current sprite. A tone is an object with R/G/B/A conponents, and it can influence the output of final pixels of current sprite.
		*
		* The result pixel will be generated using formula as follow:
		*
		* grayFull = (preColor.r * 38 + preColor.g * 75 + preColor.b * 15) / 128
		*
		* resultColor.rgb = tone.rgb + (color.rgb + (grayFull - color.rgb) * tone.a)
		*
		* @param pTone A pointer to the tone object.
		*/
		/**
		* \~chinese
		*
		* Ϊ��ǰ Sprite ����һ�� Tone ����һ�� Tone ��һ��ӵ�� R/G/B/A �����Ķ������ܹ�Ӱ�쵱ǰ Sprite ������������ء�
		*
		* ������������ؽ��ᰴ��������ʽ���ɣ�
		*
		* grayFull = (preColor.r * 38 + preColor.g * 75 + preColor.b * 15) / 128
		*
		* resultColor.rgb = tone.rgb + (color.rgb + (grayFull - color.rgb) * tone.a)
		*
		* @param pTone ָ�� Tone �����ָ�롣
		*/
		void SetTone(IrisTone*& pTone);
		/**
		* \~english
		* Get the tone object of current sprite.
		* @return The pointer to the tone object.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Sprite �� Tone ��ָ�롣
		* @return ��ǰ Sprite �� Tone ��ָ�롣
		*/
		IrisTone* GetTone() const;

		/**
		* \~english
		* Update current sprite for 1 frame. If current sprite has been set an animation, call of this function will set the animation foraward 1 frame otherwise nothing will be down.
		*/
		/**
		* \~chinese
		* �Ե�ǰ�� Sprite ����һ֡�������ǰ�� Sprite �������˶�������ô���øú��������õ�ǰ Sprite �Ķ���ǰ��һ֡��
		*/
		void Update();

		void Render();
		bool Dispose();

	private:
		IrisSprite() = default;
		~IrisSprite();

		bool CreateSpriteVertexBuffer();

		void* operator new(size_t i)
		{
			return _mm_malloc(i, 16);
		}

		void operator delete(void* p)
		{
			_mm_free(p);
		}

	};
}


#endif // !_H_IRISSPRITE_
