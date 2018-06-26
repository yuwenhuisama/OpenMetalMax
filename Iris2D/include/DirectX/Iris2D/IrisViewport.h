#ifndef _H_IRISVIEWPORT_
#define _H_IRISVIEWPORT_

#include "IrisCommon.h"
#include "Iris2D Util/IrisViewportShaderBuffers.h"

namespace Iris2D
{
	class IrisSprite;
	class IrisRect;
	class IrisTexture;
	class IrisRect;
	class IrisColor;
	typedef IrisColor IrisTone;

#if _MANAGED
#pragma unmanaged
#endif
	/**
	* \~english
	* Viewport class of Iris 2D
	*
	* A viewport is an area that limit sprite to display in the screen.
	*
	* Defautly, every sprite not specified a viewport will be put into a global viewport whose'area equals to the whole screen.
	*/
	/**
	* \~chinese
	* Iris 2D Viewport ��
	*
	* һ�� Viewport ������������ Sprite ��ʾ������
	*
	* ���һ�� Sprite û�б�ָ�� Viewport����ô���ᱻĬ�ϷŽ�һ��ȫ�ֵ� Viewport ֮�У���� Viewport ��ʾ�������ͬ���������档
	*/
	__declspec(align(16))
	class IrisViewport
	{
	private:
		std::unordered_set<IrisSprite*> m_stSprits;

		ID3D11Buffer* m_pVertexBuffer = nullptr;
		IrisTexture* m_pTexture = nullptr;

		IrisViewportVertexShaderBuffer m_ivvsVertexBuffer;
		IrisViewportPixelShaderBuffer m_ivpsPixelBuffer;

		//DirectX::XMMATRIX m_mxViewProjMatrix = DirectX::XMMatrixIdentity();

		float m_fX = 0.0f;
		float m_fY = 0.0f;
		float m_fZ = 1.0f;

		bool m_bVertexBufferDirtyFlag = false;
		bool m_bVisible = true;

		IrisRect* m_pSrcRect = nullptr;
		IrisTone* m_pTone = nullptr;

		bool m_bSrcRectDirtyFlag = false;
		bool m_bToneDirtyFlag = false;

	public:
		static IrisViewport* sm_pGlobalViewport;

	public:
		/**
		* \~english
		* Create a viewport with a rectangle area.
		* @param fX The top left position of the area.
		* @param fY The top left position of the area.
		* @param nWidth The width of the area.
		* @param nHeight The height of the area.
		* @return If viewport has been created successfully pointer of IrisViewport will be returned otherwise nullptr.
		* @ see Create(IrisRect* pRect, IR_PARAM_RESULT)
		*/
		/**
		* \~chinese
		* ����һ����������� Viewport��
		* @param fX ��������Ͻ� X ����.
		* @param fY ��������Ͻ� Y ����.
		* @param nWidth ����Ŀ��.
		* @param nHeight ����ĸ߶�.
		* @return ����ɹ����� Viewport ����ô���᷵�ظ� IrisViewport ��ָ�룬���򷵻� nullptr��
		* @see Create(IrisRect* pRect, IR_PARAM_RESULT)
		*/
		static IrisViewport* Create(float fX, float fY, unsigned int nWidth, unsigned int nHeight, IR_PARAM_RESULT);

		/**
		* \~english
		* Create a viewport with a rectangle area.
		* @param pRect The rect to specify the area.
		* @return If viewport has been created successfully pointer of IrisViewport will be returned otherwise nullptr.
		* @see Create(float fX, float fY, unsigned int nWidth, unsigned int nHeight, IR_PARAM_RESULT)
		*/
		/**
		* \~chinese
		* ����һ����������� Viewport��
		* @param pRect ����ȷ������� Rect��
		* @return ����ɹ����� Viewport ����ô���᷵�ظ� IrisViewport ��ָ�룬���򷵻� nullptr��
		* @see Create(float fX, float fY, unsigned int nWidth, unsigned int nHeight, IR_PARAM_RESULT);
		*/
		static IrisViewport* Create(const IrisRect* pRect, IR_PARAM_RESULT);

		/**
		* \~english
		* Release a Viewport.
		* @param pViewport A pointer to viewport object to be released. After this function called, pointer taken will be set to nullptr.
		*/
		/**
		* \~chinese
		* �ͷ�һ�� Viewport ��
		* @param pViewport ָ��Ҫ���ͷŵ� Viewport ��ָ�롣���ú���������֮�󣬴����ָ�뽫�ᱻ���ó� nullptr ��
		*/
		static void Release(IrisViewport*& pViewport);

		static void ManagedRelease(IrisViewport* pViewport);
		static void InnerRelease(IrisViewport*& pViewport);

		static bool InitGlobalViewport(unsigned int nWindowWidth, unsigned int nWindowHeight);
		static void ReleaseGlobalViewport();
		static IrisViewport* GetGlobalViewport();

	public:

		/**
		* \~english
		* Set origin transfer position of current viewport.
		*
		* Initially, a viewport generated into screen is put at (-OX, -OY) where OX = 0 and OY = 0 defaultly and then moved to (-0X + X, OY + Y). (-OX, OY) is called origin transfer position.
		*
		* This property can be useful for rotating with any centern position.
		* @param fOX X position of origin transfer position of current viewport.
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
		* Get X position of origin transfer position of current viewport.
		* @return X position of origin transfer position of current viewport.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Viewport �Ĵ���ԭ��� X ���ꡣ
		* @return ��ǰ Viewport �Ĵ���ԭ��� X ���ꡣ
		*/
		float GetOX() const;

		/**
		* \~english
		* Set origin transfer position of current viewport.
		*
		* Initially, a viewport generated into screen is put at (-OX, -OY) where OX = 0 and OY = 0 defaultly and then moved to (-0X + X, -OY + Y). (OX, OY) is called origin transfer position.
		*
		* This property can be useful for rotating with any centern position.
		* @param fOY Y position of origin transfer position of current viewport.
		*/
		/**
		* \~chinese
		* ���õ�ǰ Sprite �Ĵ���ԭ�㡣
		*
		* һ�������ɵ� Sprite һ��ʼ�ᱻ�ŵ���Ļ�� (-OX, -OY) ��λ�ã�Ĭ������� OX = 0 ���� OY = 0 ����Ȼ�����Żᱻ�ƶ��� ( -OX + X, -OY + Y �� ��( OX, OY ) ����Ϊ����ԭ�㡣
		*
		* ����������������Ϊ��ת���Ľ�����ת��ʱ���൱���á�
		* @param fOY ��ǰ Viewport ����ԭ��� Y ���ꡣ
		*/
		void SetOY(float fOY);
		/**
		* \~english
		* Get Y position of origin transfer position of current viewport.
		* @return Y position of origin transfer position of current viewport.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Viewport �Ĵ���ԭ��� Y ���ꡣ
		* @return ��ǰ Viewport �Ĵ���ԭ��� Y ���ꡣ
		*/
		float GetOY() const;

		/**
		* \~english
		* Set a rect to limit the display content of current viewport.
		*
		* (0, 0) of current viewport is origin position of taken rect. This function can be helpful to let viewport just show a part of it.
		* @param pSrcRect A pointer to the limit rect object.
		*/
		/**
		* \~chinese
		* ����һ�� Rect �����Ƶ�ǰ Viewport ��ʾ�����ݡ�
		*
		* ��ǰ Viewport �� (0, 0)  ���Ǵ���� Rect ��ԭ�㡣������������� Viewport ֻ��ʾ�������ݵ�һ���֡�
		* @param pSrcRect ָ������ Rect �����ָ�롣
		*/
		void SetSrcRect(IrisRect*& pSrcRect);
		/**
		* \~english
		* Get the limit rect of current viewport.
		* @return The pointer to the limit rect object.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Viewport ������ Rect ��ָ�롣
		* @return ��ǰ Viewport ������ Rect ��ָ�롣
		*/
		IrisRect* GetSrcRect() const;

		/**
		* \~english
		* Set a tone object to current viewport. A tone is an object with R/G/B/A conponents, and it can influence the output of final pixels of viewport.
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
		* Ϊ��ǰ Viewport ����һ�� Tone ����һ�� Tone ��һ��ӵ�� R/G/B/A �����Ķ������ܹ�Ӱ�쵱ǰ Viewport ������������ء�
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
		* Get the tone object of current viewport.
		* @return The pointer to the tone object.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ viewport �� Tone ��ָ�롣
		* @return ��ǰ Viewport �� Tone ��ָ�롣
		*/
		IrisTone* GetTone() const;

		bool Dispose();
		bool RenderSprite();
		bool RenderSelf();

		void AddSprite(IrisSprite* pSprite);
		void RemoveSprite(IrisSprite* pSprite);

	private:
		bool CreateViewportVertexBuffer(unsigned int nWidth, unsigned int nHeight);

		IrisViewport() = default;
		~IrisViewport();

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

#endif // !_H_IRISVIEWPORT_
