#ifndef FONT_H
#define FONT_H

#include <string>

struct TTF_Font;
namespace dae
{
	/**
	 * Simple RAII wrapper for a TTF_Font
	 */
	class Font final
	{
	public:
		TTF_Font* GetFont() const;

		explicit Font(std::string const& fullPath, float size);
		~Font();
		Font(Font const&) = delete;
		Font(Font&&) = delete;
		Font& operator= (Font const&) = delete;
		Font& operator= (Font const&&) = delete;

	private:
		TTF_Font* m_font;
	};
}
#endif // !FONT_H