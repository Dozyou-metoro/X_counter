#include<Siv3D.hpp>

enum {
	count_mode,
	config_mode,
};

bool botton_pressed(const Rect& botton_rect, const Color& rect_color, const Font& font, const Color& text_color, const String& text) {
	if (botton_rect.mouseOver() == false) {//ポインターが上に無いとき
		botton_rect.draw(rect_color);

		font(text).drawAt(botton_rect.x + botton_rect.w / 2, botton_rect.y + botton_rect.h / 2, text_color);

		return false;
	}
	else if (botton_rect.leftPressed() == false) {//ポインターが上にあって押されていない時
		botton_rect.draw(rect_color);

		font(text).drawAt(botton_rect.x + botton_rect.w / 2, botton_rect.y + botton_rect.h / 2, text_color);
		Cursor::RequestStyle(CursorStyle::Hand);

		return false;
	}
	else {//押されたとき
		Color buf_color = rect_color;

		buf_color.r *= 0.9;
		buf_color.g *= 0.9;
		buf_color.b *= 0.9;

		Rect buf_rect = botton_rect;

		buf_rect.x += 3;
		buf_rect.y += 3;
		buf_rect.w -= 6;
		buf_rect.h -= 6;


		buf_rect.draw(buf_color);

		Color buf_textcolor = text_color;

		buf_textcolor.r *= 0.9;
		buf_textcolor.g *= 0.9;
		buf_textcolor.b *= 0.9;


		font(text).drawAt(font.fontSize() * 0.9, botton_rect.x + botton_rect.w / 2, botton_rect.y + botton_rect.h / 2, text_color);
		Cursor::RequestStyle(CursorStyle::Hand);


		return true;
	}


	return false;
}

bool botton_Clicked(const Rect& botton_rect, const Color& rect_color, const Font& font, const Color& text_color, const String& text) {
	if (botton_rect.mouseOver() == false) {//ポインターが上に無いとき
		botton_rect.draw(rect_color);

		font(text).drawAt(botton_rect.x + botton_rect.w / 2, botton_rect.y + botton_rect.h / 2, text_color);

		return false;
	}
	else if (botton_rect.leftClicked() == false) {//ポインターが上にあって押されていない時
		botton_rect.draw(rect_color);

		font(text).drawAt(botton_rect.x + botton_rect.w / 2, botton_rect.y + botton_rect.h / 2, text_color);
		Cursor::RequestStyle(CursorStyle::Hand);

		return false;
	}
	else {//押されたとき
		Color buf_color = rect_color;

		buf_color.r *= 0.9;
		buf_color.g *= 0.9;
		buf_color.b *= 0.9;

		Rect buf_rect = botton_rect;

		buf_rect.x += 3;
		buf_rect.y += 3;
		buf_rect.w -= 6;
		buf_rect.h -= 6;


		buf_rect.draw(buf_color);

		Color buf_textcolor = text_color;

		buf_textcolor.r *= 0.9;
		buf_textcolor.g *= 0.9;
		buf_textcolor.b *= 0.9;


		font(text).drawAt(font.fontSize() * 0.9, botton_rect.x + botton_rect.w / 2, botton_rect.y + botton_rect.h / 2, text_color);
		Cursor::RequestStyle(CursorStyle::Hand);


		return true;
	}


	return false;
}

void Main(void) {
	String text = U"そめいん";//表示するテキスト
	uint8 mode_flag = 0;//モード

	int64 count = 0;

	Font font(FontMethod::MSDF, 40, U"C:\\Users\\Kouno\\kura\\フォント\\corpgo-b-ver2-font_202202\\corpgo-b-ver2-font_202202\\Corporate-Logo-Bold-ver2.otf");


	while (System::Update()) {
		switch (mode_flag) {
		case count_mode:
			Scene::SetBackground(Palette::Skyblue);

			font(text).drawAt(100, 400, 50, Color{ 150, 150,150 });

			font(count).drawAt(200, 400, 200, Color{ 150, 150,150 });

			if (botton_Clicked(Rect(110, 330, 580, 150), Color{ 255, 255,255 }, font, Color{ 150, 150,150 }, U"+1") == true) {
				count++;
			}

			if (botton_Clicked(Rect(110, 500, 580, 50), Color{ 255, 255,255 }, font, Color{ 150, 150,150 }, U"-1") == true) {
				count--;
			}

			if (botton_pressed(Rect(700, 550, 100, 50), Color{ 255, 255,255 }, font, Color{ 150, 150,150 }, U"設定") == true) {
				mode_flag = config_mode;
			}

			break;

		default:

			mode_flag = count_mode;
			break;
		}
	}
}



