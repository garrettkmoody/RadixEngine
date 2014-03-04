#include "GameScreen.hpp"

namespace glPortal {
  namespace engine {
    namespace gui {
      GameScreen::GameScreen(Window &window){
	this->window = window;
	Timer* timer = new Timer();
	this->gameTimer = *timer;
	this->gameTimer.start();
      }

      void GameScreen::beginOverlay() {
	int height = window.getHeight();
	int width  = window.getWidth();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0,width,height,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_DEPTH_TEST);
      }

      void GameScreen::endOverlay() {
	glEnable(GL_DEPTH_TEST);
	// Restore perspective projection matrix
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
      }

      void GameScreen::drawPauseScreen() {
	int height = window.getHeight();
	int width  = window.getWidth();
	// Add dark tint to screen
	glColor4f(0.f, 0.f, 0.f, 0.5f);
	glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glVertex2f(  0.f,    0.f);
	glVertex2f(  0.f, height);
	glVertex2f(width, height);
	glVertex2f(width,    0.f);
	glEnd();
	// Draw "Paused" message
	glEnable(GL_TEXTURE_2D);
	glColor4f(1.f, 1.f, 1.f, 1.f);
	Resources::inst().bindTexture(TID_STRINGS);
	glBegin(GL_QUADS);
	glTexCoord2f(0.00f, 0.125f); glVertex2f(width/2-64, height/2-32);
	glTexCoord2f(0.00f, 0.250f); glVertex2f(width/2-64, height/2+32);
	glTexCoord2f(0.25f, 0.250f); glVertex2f(width/2+64, height/2+32);
	glTexCoord2f(0.25f, 0.125f); glVertex2f(width/2+64, height/2-32);
	glEnd();
      }

      void GameScreen::drawCrosshair() {
	int height = window.getHeight();
	int width  = window.getWidth();
	Resources::inst().bindTexture(TID_CROSSHAIR);
	glColor4f(1.f, 1.f, 1.f, 1.f);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex2f(width/2-16, height/2-12);
	glTexCoord2f(0,1); glVertex2f(width/2-16, height/2+20);
	glTexCoord2f(1,1); glVertex2f(width/2+16, height/2+20);
	glTexCoord2f(1,0); glVertex2f(width/2+16, height/2-12);
	glEnd();
      }

      void GameScreen::drawGameOverScreen() {
	int height = window.getHeight();
	int width  = window.getWidth();
	float fade = 0.5f;
	glColor4f(0.f, 0.f, 0.f, fade);
	glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glVertex2f(  0.f,    0.f);
	glVertex2f(  0.f, height);
	glVertex2f(width, height);
	glVertex2f(width,    0.f);
	glEnd();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.f, 1.f, 1.f);
      }

      void GameScreen::drawRespawnScreen() {
	int height = window.getHeight();
	int width  = window.getWidth();
	Resources::inst().bindTexture(TID_STRINGS);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0.000f); glVertex2f(width/2-256, height/2-32);
	glTexCoord2f(0, 0.125f); glVertex2f(width/2-256, height/2+32);
	glTexCoord2f(1, 0.125f); glVertex2f(width/2+256, height/2+32);
	glTexCoord2f(1, 0.000f); glVertex2f(width/2+256, height/2-32);
	glEnd();
      }

      void GameScreen::drawContinueScreen() {
	int height = window.getHeight();
	int width  = window.getWidth();
	Resources::inst().bindTexture(TID_STRINGS);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0.25f); glVertex2f(width/2-256, height/2-64);
	glTexCoord2f(0, 0.50f); glVertex2f(width/2-256, height/2+64);
	glTexCoord2f(1, 0.50f); glVertex2f(width/2+256, height/2+64);
	glTexCoord2f(1, 0.25f); glVertex2f(width/2+256, height/2-64);
	glEnd();
      }

      void GameScreen::drawTimer(std::string timeString){
	
	Font* font = new Font();
	font->drawStringToPosition(timeString, 10, 19);
      }


      void GameScreen::drawTestTextScreen(){
	
	Font* font = new Font();
	//font->drawStringToPosition("10:12:55", 10, 19);
	font->drawStringToPosition(this->gameTimer.getTimeString(), 10, 19);
      }
    }
  }
}
