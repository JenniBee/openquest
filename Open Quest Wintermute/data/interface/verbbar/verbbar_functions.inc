global Command;
global Object2;
global Object1;

global button_lookat;
global button_talkto;
global button_pickup;
global button_use;
global button_give;
global button_move;
global button_open;
global button_smell;

global lookat_over;
global talkto_over;
global pickup_over;
global use_over;
global give_over;
global move_over;
global open_over;
global smell_over;

global widget_button_lookat;
global widget_button_talkto;
global widget_button_pickup;
global widget_button_use;
global widget_button_give;
global widget_button_move;
global widget_button_open;
global widget_button_smell;

function verb_setBar(caption)
{
  Command.Running = caption;
}

function verb_initBar()
{
  lookat_over  = false;
  talkto_over  = false;
  pickup_over  = false;
  use_over     = false;
  give_over    = false;
  move_over   = false;
  open_over   = false;
  smell_over   = false;

  widget_button_lookat  = WinMenu.GetWidget("LookAtContainer");
  widget_button_talkto  = WinMenu.GetWidget("TalkToContainer");
  widget_button_pickup  = WinMenu.GetWidget("PickUpContainer");
  widget_button_use     = WinMenu.GetWidget("UseContainer");
  widget_button_give    = WinMenu.GetWidget("GiveContainer");
  widget_button_move    = WinMenu.GetWidget("MoveContainer");
  widget_button_open    = WinMenu.GetWidget("OpenContainer");
  widget_button_smell   = WinMenu.GetWidget("SmellContainer");

  button_lookat = widget_button_lookat.GetEntity();
  button_talkto = widget_button_talkto.GetEntity();
  button_pickup = widget_button_pickup.GetEntity();
  button_use    = widget_button_use.GetEntity();
  button_give   = widget_button_give.GetEntity();
  button_move   = widget_button_move.GetEntity();
  button_open   = widget_button_open.GetEntity();
  button_smell  = widget_button_smell.GetEntity();

  Command.Running = "";
}

function verb_cleanBar()
{
  Command.Verb = "";
  Command.Object1_caption = "";
  Command.Object1_name = "";
  Command.Object1 = "";
  Command.Object2_caption = "";
  Command.Object2_name = "";
  Command.Object2 = "";
  Command.Running = "";
  
  lookat_over=false;
  talkto_over=false;
  pickup_over=false;
  use_over=false;
  give_over=false;
  move_over=false;
  open_over=false;
  smell_over=false;

  button_lookat.SetSprite("interface\verbbar\lookat_off.bmp");
  button_talkto.SetSprite("interface\verbbar\talkto_off.bmp");
  button_pickup.SetSprite("interface\verbbar\pickup_off.bmp");
  button_use.SetSprite("interface\verbbar\use_off.bmp");
  button_give.SetSprite("interface\verbbar\give_off.bmp");
  button_move.SetSprite("interface\verbbar\move_off.bmp");
  button_open.SetSprite("interface\verbbar\open_off.bmp");
  button_smell.SetSprite("interface\verbbar\smell_off.bmp");

  var ActObj = Game.ActiveObject;
  if(ActObj!=null) ActObj.ApplyEvent("MouseEntry");
}

function verb_hover(hoverme)
{
  if(Command.Verb != hoverme)
  {
    switch(hoverme)
    {
      case "Examine":
        button_lookat.SetSprite("interface\verbbar\lookat_def.bmp");
        break;
      case "Talk to":
        button_talkto.SetSprite("interface\verbbar\talkto_def.bmp");
        break;
      case "Pick up":
        button_pickup.SetSprite("interface\verbbar\pickup_def.bmp");
        break;
      case "Use":
        button_use.SetSprite("interface\verbbar\use_def.bmp");
        break;
      case "Give":
        button_give.SetSprite("interface\verbbar\give_def.bmp");
        break;
      case "Move":
        button_move.SetSprite("interface\verbbar\move_def.bmp");
        break;
      case "Open":
        button_open.SetSprite("interface\verbbar\open_def.bmp");
        break;
      case "Smell":
        button_smell.SetSprite("interface\verbbar\smell_def.bmp");
        break;
    }
  }
}

function verb_unhover(unhoverme)
{
  if(Command.Verb != unhoverme)
  {
    switch(unhoverme)
    {
      case "Examine":
        button_lookat.SetSprite("interface\verbbar\lookat_off.bmp");
        break;
      case "Pick up":
        button_pickup.SetSprite("interface\verbbar\pickup_off.bmp");
        break;
      case "Talk to":
        button_talkto.SetSprite("interface\verbbar\talkto_off.bmp");
        break;
      case "Use":
        button_use.SetSprite("interface\verbbar\use_off.bmp");
        break;
      case "Give":
        button_give.SetSprite("interface\verbbar\give_off.bmp");
        break;
      case "Move":
        button_move.SetSprite("interface\verbbar\move_def.bmp");
        break;
      case "Open":
        button_open.SetSprite("interface\verbbar\open_def.bmp");
        break;
      case "Smell":
        button_smell.SetSprite("interface\verbbar\smell_def.bmp");
        break;
    }
  }
  else
  {
    switch(unhoverme)
    {
      case "Examine":
        button_lookat.SetSprite("interface\verbbar\lookat_on.bmp");
        break;
      case "Pick up":
        button_pickup.SetSprite("interface\verbbar\pickup_on.bmp");
        break;
      case "Talk to":
        button_talkto.SetSprite("interface\verbbar\talkto_on.bmp");
        break;
      case "Use":
        button_use.SetSprite("interface\verbbar\use_on.bmp");
        break;
      case "Give":
        button_give.SetSprite("interface\verbbar\give_on.bmp");
        break;
      case "Move":
        button_move.SetSprite("interface\verbbar\move_on.bmp");
        break;
      case "Open":
        button_open.SetSprite("interface\verbbar\open_on.bmp");
        break;
      case "Smell":
        button_smell.SetSprite("interface\verbbar\smell_on.bmp");
        break;
    }
  }
}

function verb_apply(appverb)
{
  verb_cleanBar();
  Command.Verb = appverb;
  switch(appverb)
  {
    case "Examine":
      button_lookat.SetSprite("interface\verbbar\lookat_on.bmp");
      self.ApplyEvent("LookAt");
      break;
    case "Pick up":
      button_pickup.SetSprite("interface\verbbar\pickup_on.bmp");
      self.ApplyEvent("PickUp");
      break;
    case "Talk to":
      button_talkto.SetSprite("interface\verbbar\talkto_on.bmp");
      self.ApplyEvent("TalkTo");
      break;
    case "Use":
      button_use.SetSprite("interface\verbbar\use_on.bmp");
      self.ApplyEvent("Use");
      break;
    case "Give":
      button_give.SetSprite("interface\verbbar\give_on.bmp");
      self.ApplyEvent("Give");
      break;
    case "Move":
      button_move.SetSprite("interface\verbbar\move_on.bmp");
      self.ApplyEvent("Move");
      break;
    case "Open":
      button_open.SetSprite("interface\verbbar\open_on.bmp");
      self.ApplyEvent("Open");
      break;
    case "Smell":
      button_open.SetSprite("interface\verbbar\smell_on.bmp");
      self.ApplyEvent("Smell");
      break;
  }
}

function verb_doesNotWork()
{
  var ran;
  switch(Command.Verb)
  {
    case "Examine":
      actor.Talk("Looks pretty ordinary.");
      break;
    case "Talk to":
      actor.Talk("I don't know how to communicate with that.");
      break;
    case "Pick up":
      actor.Talk("I don't need that.");
      break;
    case "Use":
      ran = Random(0,1);
      if(ran==0) actor.Talk("That doesn't work!");
      if(ran==1) actor.Talk("That makes no sense at all!");
      break;
    case "Give":
      actor.Talk("Nah.");
      break;
    case "Move":
      actor.Talk("I can't move that!");
      break;
    case "Open":
      actor.Talk("That doesn't seem to open.");
      break;
    case "Smell":
      actor.Talk("That has no odour.");
      break;
  }
}

function verb_switchButtons(mode)
{
  switch(mode)
  {
    case 1:
      widget_button_lookat.Visible  = true;
      widget_button_talkto.Visible  = true;
      widget_button_pickup.Visible  = true;
      widget_button_use.Visible     = true;
      widget_button_give.Visible    = true;
      widget_button_move.Visible    = true;
      widget_button_open.Visible    = true;
      widget_button_smell.Visible   = true;
      break;
    case 0:
    default:
      widget_button_lookat.Visible  = false;
      widget_button_talkto.Visible  = false;
      widget_button_pickup.Visible  = false;
      widget_button_use.Visible     = false;
      widget_button_give.Visible    = false;
      widget_button_move.Visible    = false;
      widget_button_open.Visible    = false;
      widget_button_smell.Visible   = false;
      break;
  }
}

function verb_changeMode(mode)
{
  switch(mode)
  {
    case 2:
      WinMenu.SetImage("interface\verbbar\no_verbbar.bmp");
      Game.InventoryVisible = false;
      verb_switchButtons(0);
      break;
    case 1:
      WinMenu.SetImage("interface\verbbar\verbbar_talk.bmp");
      Game.InventoryVisible = false;
      verb_switchButtons(0);
      break;
    case 0:
    default:
      WinMenu.SetImage("interface\verbbar\verbbar.bmp");
      Game.InventoryVisible = true;
      verb_switchButtons(1);
      break;
  }
}

function verb_showBar()
{
  Game.InventoryVisible = true;
  WinMenu.Visible = true;
  verb_switchButtons(1);
}

function verb_hideBar()
{
  Game.InventoryVisible = false;
  WinMenu.Visible = false;
  verb_switchButtons(0);
}
